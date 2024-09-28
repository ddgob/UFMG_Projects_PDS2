#ifndef COTACAO_HPP
#define COTACAO_HPP
#include <string>
using namespace std;

struct Cotacao {
    string data;
    double valor;

    Cotacao(string _data, double _valor);
    Cotacao();

    string get_data();
    double get_valor();
};

#endif