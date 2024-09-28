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

    // Vetor que contém "true" para os elementos que 
    //foram inicializados
    std::vector<bool> inicializado();
  
  private:
    int inicio_;  // Primeiro índice válido do arranjo.
    int fim_;  // Último índice válido do arranjo.
    std::vector<Tipo> elementos_;  // Elementos do arranjo.
    // Indica quais elementos foram inicializados do arranjo.
    std::vector<int> inicializados_;
};

// DEFINIÇÃO DAS CLASSES DE EXCEÇÃO.
struct ExcecaoIntervaloVazio {
  // Completar. Vide main.cpp.
  int inicio;
  int fim;
};

struct ExcecaoIndiceInvalido {
  // Completar. Vide main.cpp.
  int indice;
  int inicio;
  int fim;
};

struct ExcecaoIndiceNaoInicializado {
  // Completar. Vide main.cpp.
  int indice;
};

// IMPLEMENTAÇÃO DOS MÉTODOS DA CLASSE.

template <class Tipo> 
Arranjo<Tipo>::Arranjo(int inicio, int fim) {
  if (fim < inicio) throw ExcecaoIntervaloVazio{inicio, fim};
  inicio_ = inicio;
  fim_ = fim;
  elementos_.resize(fim - inicio + 1);
  inicializados_.resize(fim - inicio + 1);
}

template <class Tipo> 
void Arranjo<Tipo>::atribuir(int i, Tipo valor) {
  if (i < inicio_ || i > fim_) throw ExcecaoIndiceInvalido{i, inicio_, fim_};
  int j = i - inicio_;
  elementos_[j] = valor;
  inicializados_[j] = 1;
}

template <class Tipo> 
Tipo Arranjo<Tipo>::valor(int i) const {
  if (i < inicio_ || i > fim_) throw ExcecaoIndiceInvalido{i, inicio_, fim_};
  int j = i - inicio_;
  if (inicializados_[j] == 0) throw ExcecaoIndiceNaoInicializado{i};
  return elementos_[j];
}