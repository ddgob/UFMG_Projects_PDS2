#include "ContadorDePalavras.hpp"
using namespace std;
#include "Palavra.hpp"
#include <iostream>

ContadorDePalavras::ContadorDePalavras() {}

void ContadorDePalavras::Adicionar(string s) {
    Palavra word(s);
    if (_lista_de_palavras.begin() == _lista_de_palavras.end()) {
        _lista_de_palavras.push_back(word);
    }else {
        list<Palavra>::iterator it;
        for (it = _lista_de_palavras.begin(); it != _lista_de_palavras.end(); it++) {
            if (it->palavra() == word.palavra()) {
                it->Incrementar();
                break;
            }else if (it == --_lista_de_palavras.end()) {
                _lista_de_palavras.push_back(word);
                break;
            }
        }
    }
    
}

void ContadorDePalavras::ImprimirOrdenado() {
    list<Palavra>::iterator it;
    int counter = 0;
    int origSize = _lista_de_palavras.size();
    while (counter < origSize) {
        Palavra temp = *_lista_de_palavras.begin();
        list<Palavra>::iterator tempLocal = _lista_de_palavras.begin();
        for (it = _lista_de_palavras.begin()++; it != _lista_de_palavras.end(); it++) {
            if (it->operator<(temp) || _lista_de_palavras.begin() == _lista_de_palavras.end()) {
              temp = *it;
              tempLocal = it;
            }
        }
        _lista_de_palavras.erase(tempLocal);
        cout << temp.palavra() << " " << temp.ocorrencias() << endl;
        counter++;
    }
}