#pragma once
#include <cassert>
#include <vector>

// Define um arranjo de qualquer Tipo cujos índices variam em
// qualquer intervalo, inclusive negativos.
template <class Tipo> 
class Arranjo {
  public:
    // Cria um arranjo cujos índices variam de 'inicio' até 'fim'.
    // PRECONDIÇÃO: fim >= inicio.
    Arranjo(int inicio, int fim);

    // Altera o valor do índice i.
    // PRECONDIÇÃO: i está dentro do intervalo de índices do vetor.
    void atribuir(int i, Tipo valor);

    // Retorna o valor do índice i.
    // PRECONDIÇÕES: 
    // (1) i está dentro do intervalo de índices do vetor.
    // (2) i foi inicializando anteriormente.
    Tipo valor(int i) const; 
  
  private:
    int inicio_;  // Primeiro índice válido do arranjo.
    int fim_;  // Último índice válido do arranjo.
    std::vector<Tipo> elementos_;  // Elementos do arranjo.
    // Indica quais elementos foram inicializados do arranjo.
    std::vector<int> inicializados_;
};

// IMPLEMENTAÇÃO DOS MÉTODOS DA CLASSE.

template <class Tipo> 
Arranjo<Tipo>::Arranjo(int inicio, int fim) {
  assert(fim >= inicio);
  inicio_ = inicio;
  fim_ = fim;
  elementos_.resize(fim - inicio + 1);
  inicializados_.resize(fim - inicio + 1);
}

template <class Tipo> 
void Arranjo<Tipo>::atribuir(int i, Tipo valor) {
  assert(i >= inicio_ && i <= fim_);
  int j = i - inicio_;
  elementos_[j] = valor;
  inicializados_[j] = 1;
}

template <class Tipo> 
Tipo Arranjo<Tipo>::valor(int i) const {
  assert(i >= inicio_ && i <= fim_);
  int j = i - inicio_;
  assert(inicializados_[j] != 0);   
  return elementos_[j];
}