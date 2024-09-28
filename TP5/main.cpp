// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_bst.hpp"
#include <iostream>
#include <string>
using namespace std;
#include "BST.hpp"

int main() {
  
    // NÃO ALTERE ESSA LINHA
    avaliacao_basica();


    //
    // Adicione seu código aqui e faça as demais alterações necessárias
    //
    BST UFMG;
    int matricula;
    string nome;
    while (cin>>matricula>>nome) {
        Aluno temp(nome, matricula);
        UFMG.inserir_aluno(temp);
    }
    // Aluno a1("Marcos", 2015999000);
    // Aluno a2("Daniel", 2015888999);
    // Aluno a3("Fernanda", 2015777888);
    // Aluno a4("Gabriel", 2015666777);
    // Aluno a5("Joana", 2015555666);
    // Aluno a6("Carolina", 2015444555);
    // Aluno a7("Felipe", 2015333444);
    // Aluno a8("Carlos", 2015222333);
    // Aluno a9("Maria", 2015111222);
    // Aluno a10("João", 2015000111);
    // UFMG.inserir_aluno(a1);
    // UFMG.inserir_aluno(a2);
    // UFMG.inserir_aluno(a3);
    // UFMG.inserir_aluno(a4);
    // UFMG.inserir_aluno(a5);
    // UFMG.inserir_aluno(a6);
    // UFMG.inserir_aluno(a7);
    // UFMG.inserir_aluno(a8);
    // UFMG.inserir_aluno(a9);
    // UFMG.inserir_aluno(a10);






    //
    // Ao final faça uma chamada para o método 'imprimir_arvore()'
    //
    UFMG.imprimir_arvore();



    return 0;
}