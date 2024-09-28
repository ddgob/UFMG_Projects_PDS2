#include "BST.hpp"
#include <string>
using namespace std;

BST::BST() {}

NodeT* createNode(string nome, int matricula) {
    NodeT* aux = new NodeT;
    aux->aluno.nome = nome;
    aux->aluno.matricula = matricula;
    aux->esq = nullptr;
    aux->dir = nullptr;

    return aux;
}

void BST::insertNodeHelper(NodeT* n, Aluno aluno) {
    if(aluno.matricula < n->aluno.matricula) {
        if(n->esq == nullptr) {
            n->esq = createNode(aluno.nome, aluno.matricula);
        }else {
            insertNodeHelper(n->esq, aluno);
        }
    }else if(aluno.matricula > n->aluno.matricula) {
        if(n->dir == nullptr) {
            n->dir = createNode(aluno.nome, aluno.matricula);
        }else {
            insertNodeHelper(n->dir, aluno);
        }
    }
}

void BST::inserir_aluno(Aluno aluno) {
    if(root != nullptr) {
        insertNodeHelper(root, aluno);
    }else {
        root = createNode(aluno.nome, aluno.matricula);
    }
}

void BST::inOrderPrint(NodeT* n) {
    if(n == nullptr) {
        return;
    }
    inOrderPrint(n->esq);
    n->aluno.imprimir_dados();
    inOrderPrint(n->dir);
}

void BST::imprimir_arvore() {
    inOrderPrint(root);
    cout << endl;    
}

Aluno* BST::inOrderSearch(NodeT* n, int matricula) {
    Aluno* alunoEncontrado = nullptr;
    if(n == nullptr) {
        return nullptr;
    }
    alunoEncontrado = inOrderSearch(n->esq, matricula);
    if(n->aluno.matricula == matricula) {
        return &n->aluno;
    }
    if(alunoEncontrado == nullptr) {
        alunoEncontrado = inOrderSearch(n->dir, matricula);
    }
    return alunoEncontrado;
}

Aluno* BST::procurar_aluno(int matricula) {
    return inOrderSearch(root, matricula);
}

