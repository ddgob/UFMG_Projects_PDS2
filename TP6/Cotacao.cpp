#include "Cotacao.hpp"

Cotacao::Cotacao(string _data, double _valor) {
    data = _data;
    valor = _valor;
}

Cotacao::Cotacao() {
    data = "00/00/0000";
    valor = 0;
}

string Cotacao::get_data() {
    return data;
}

double Cotacao::get_valor() {
    return valor;
}
