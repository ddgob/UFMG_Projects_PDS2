#include <iostream>

#include "RingArray.h"

void fer_assert(const bool expr, const char* msg) {
  if (expr) {
    std::cout << msg << std::endl;
    exit(1);
  }
}

template <class T, unsigned N>
void RingArray<T, N>::add(T value) {
  fer_assert(isFull(), "Erro: anel cheio.");
  buf[(_last % N)] = value;
  _last++;
}

template <class T, unsigned N>
T RingArray<T, N>::get() {
  fer_assert(isEmpty(), "Erro: anel vazio."); 
  T oldest = buf[(_first % N)];
  _first++;
  return oldest;
}

template <class T, unsigned N>
bool RingArray<T, N>::isFull() const {
  if (_last == _first + N - 1) return true;
  return false;
}

template <class T, unsigned N>
bool RingArray<T, N>::isEmpty() const {
  if (_last == _first) return true;
  return false;
}

template <class T>
void test_add_then_get() {
  RingArray<T, 8> r;
  T value;
  while (std::cin >> value) {
    r.add(value);
  }
  while (!r.isEmpty()) {
    std::cout << r.get() << std::endl;
  }
}

template <class T>
void test_add_or_get() {
  RingArray<T, 8> r;
  T value;
  char c;
  while (std::cin >> c) {
    if (c == '+') {
      std::cin >> value;
      r.add(value);
    } else if (c == '-') {
      std::cout << r.get() << std::endl;
    } else {
      std::cout << "Invalid operation\n";
    }
  }
}

int main () {
  char data;
  while (std::cin >> data) {
    switch (data) {
      case 'd': test_add_then_get<double>();
                break;
      case 's': test_add_then_get<std::string>();
                break;
      case 'D': test_add_or_get<double>();
                break;
      case 'S': test_add_or_get<std::string>();
                break;
      default: std::cout << "Invalid type\n";
    }
  }
  return 0;
}