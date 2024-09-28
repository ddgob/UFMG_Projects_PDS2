#ifndef ALUNO_H
#define ALUNO_H
#include <string>
#include <iostream>
using namespace std;

struct Aluno {
    string nome;
    int matricula;
    //Alterar o aluno para ele mesmo ser um node, ou seja, criar um ponteiro esq e dir

    Aluno(string _nome, int _matricula);
    Aluno() = default;
    string get_nome();
    int get_matricula();
    void set_nome(string _nome);
    void set_matricula(int _matricula);
    
    
    void imprimir_dados();
};


#endif