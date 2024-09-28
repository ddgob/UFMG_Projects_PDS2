#include <string>
#include "Aluno.hpp"
using namespace std;

Aluno::Aluno(string _nome, int _matricula) {
    nome = _nome;
    matricula = _matricula;
}

string Aluno::get_nome() {
    return nome;
}

int Aluno::get_matricula() {
    return matricula;
}

void Aluno::set_nome(string _nome) {
    nome = _nome;
}

void Aluno::set_matricula(int _matricula) {
    matricula = _matricula;
}

void Aluno::imprimir_dados() {
    cout << matricula << " " << nome << endl;
}