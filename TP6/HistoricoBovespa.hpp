#ifndef HISTORICOBOVESPA_HPP
#define HISTORICOBOVESPA_HPP
#include "Cotacao.hpp"
#include <vector>
#include <map>

struct HistoricoBovespa {
    map<string, vector<Cotacao>> mapa;

    HistoricoBovespa();

    void inserir_cotacao(string sigla, string data, double valor);
    double calcular_valor_medio_acao(string sigla);
    Cotacao* recuperar_cotacao_maxima_acao(string sigla);
    Cotacao* recuperar_cotacao_minima_acao(string sigla);
    void imprimir_estatisticas_completas(); 

};

#endif