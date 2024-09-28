#include "fila_de_prioridade.h"

FilaDePrioridade::FilaDePrioridade() {
    tamanho_ = 0;
    primeiro_ = nullptr;
}

string FilaDePrioridade::primeiro() const {
    if (!vazia()) {
        return primeiro_->nome;
    }
}

int FilaDePrioridade::tamanho() const {
    return tamanho_;
}

bool FilaDePrioridade::vazia() const {
    if (tamanho_ == 0) return true;
    return false;
}

void FilaDePrioridade::RemoverPrimeiro() {
    if (!vazia()) {
        No* a_ser_removido = primeiro_;
        primeiro_ = primeiro_->proximo;
        delete a_ser_removido;
        tamanho_--;
    }
}

void FilaDePrioridade::Inserir(int p, string s) {
    No* aux = new No;
    aux->idade = p;
    aux->nome = s;
    aux->proximo = nullptr;
    if (primeiro_ == nullptr) {
        primeiro_ = aux;
        tamanho_++;
        return;
    }
    for (No* it = primeiro_; it != nullptr; it = it->proximo) {
        if (aux->idade > it->idade) {
            aux->nome = it->nome;
            aux->idade = it->idade;
            aux->proximo = it->proximo;
            it->nome = s;
            it->idade = p;
            it->proximo = aux;
            tamanho_++;
            return;
        }
        if (it->proximo == nullptr) {
            it->proximo = aux;
            tamanho_++;
            return;
        }
    }
}

void FilaDePrioridade::Limpar() {
    for (No* it = primeiro_; it != nullptr; it->proximo) {
        delete it;
    }
    primeiro_ = nullptr;
    tamanho_ = 0;
}