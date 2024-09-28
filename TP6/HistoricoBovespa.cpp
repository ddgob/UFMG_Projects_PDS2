#include "HistoricoBovespa.hpp"
#include <iostream>

HistoricoBovespa::HistoricoBovespa() {}

void HistoricoBovespa::inserir_cotacao(string sigla, string data, double valor) {
    Cotacao nova(data, valor);
    if(mapa.find(sigla) == mapa.end()) {
        vector<Cotacao> cotacao;
        cotacao.push_back(nova);
        mapa.insert(pair<string, vector<Cotacao>> (sigla, cotacao));
    }else {
        mapa.find(sigla)->second.push_back(nova);
    }
}

double HistoricoBovespa::calcular_valor_medio_acao(string sigla) {
    double somaDasCotacoes = 0;
    vector<Cotacao> temp = mapa.find(sigla)->second;
    int tempSize = temp.size();
    for(int i = 0; i < tempSize; i++) {
        somaDasCotacoes += temp[i].get_valor();
    }
    return somaDasCotacoes/tempSize;
}

Cotacao* HistoricoBovespa::recuperar_cotacao_maxima_acao(string sigla) {
    vector<Cotacao> temp = mapa.find(sigla)->second;
    if(temp.empty()) return nullptr;
    int tempSize = temp.size();
    double maiorCotacao = 0;
    Cotacao* ponteiroMaiorCotacao = nullptr;
    for(int i = 0; i < tempSize; i++) {
        if(maiorCotacao < temp[i].get_valor()) {
            maiorCotacao = temp[i].get_valor();
            ponteiroMaiorCotacao = &mapa.find(sigla)->second[i];
        }
    }
    return ponteiroMaiorCotacao;
}

Cotacao* HistoricoBovespa::recuperar_cotacao_minima_acao(string sigla) {
    vector<Cotacao> temp = mapa.find(sigla)->second;
    if(temp.empty()) return nullptr;
    int tempSize = temp.size();
    double menorCotacao = temp[0].get_valor();
    Cotacao* ponteiroMenorCotacao = &mapa.find(sigla)->second[0];
    for(int i = 0; i < tempSize; i++) {
        if(menorCotacao > temp[i].get_valor()) {
            menorCotacao = temp[i].get_valor();
            ponteiroMenorCotacao = &mapa.find(sigla)->second[i];
        }
    }
    return ponteiroMenorCotacao;
}

void HistoricoBovespa::imprimir_estatisticas_completas() {
    map<string, vector<Cotacao>>::iterator it;
    for(it = mapa.begin(); it != mapa.end(); it++) {
        cout << it->first << " ";
        int tempSize = it->second.size();
        for(int i = 0; i < tempSize; i++) {
            cout << it->second[i].get_valor() << " ";
        }
        cout << "| ";
        cout << recuperar_cotacao_minima_acao(it->first)->get_valor() << " ";
        cout << recuperar_cotacao_maxima_acao(it->first)->get_valor() << " ";
        cout << calcular_valor_medio_acao(it->first) << " " << endl;
    }
}