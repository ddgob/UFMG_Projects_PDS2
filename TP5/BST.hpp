#ifndef BST_H
#define BST_H
#include "Aluno.hpp"
#include <string>
using namespace std;

struct NodeT {
    Aluno aluno;
    NodeT* esq;
    NodeT* dir;
};

struct BST {
    NodeT* root = nullptr;

    BST();
    void insertNodeHelper(NodeT* n, Aluno aluno);
    void inserir_aluno(Aluno aluno);
    void inOrderPrint(NodeT* n);
    void imprimir_arvore();
    Aluno* inOrderSearch(NodeT* n, int matricula);
    Aluno* procurar_aluno(int matricula);

};

#endif