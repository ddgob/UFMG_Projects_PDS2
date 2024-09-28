// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_bovespa.hpp"
#include "HistoricoBovespa.hpp"

int main() {
  
    // NÃO ALTERE ESSA LINHA
    avaliacao_basica();


    //
    // Adicione seu código aqui e faça as demais alterações necessárias
    //
    HistoricoBovespa Bovespa;
    string sigla, data;
    double valor;
    while(cin >> sigla >> data >> valor) {
        Bovespa.inserir_cotacao(sigla, data, valor);
    }

    //
    // Ao final faça uma chamada para o método 'imprimir_estatisticas_completas()'
    //
    Bovespa.imprimir_estatisticas_completas();


    return 0;
}