#include "Triangulo.hpp"
#include <cmath>

Triangulo::Triangulo(Ponto2D p1, Ponto2D p2, Ponto2D p3) {
    A = p1;
    B = p2;
    C = p3;
}

double Triangulo::calcular_area() {
    double p = calcular_perimetro()/2;
    double lado1 = A.calcular_distancia(&B);
    double lado2 = B.calcular_distancia(&C);
    double lado3 = C.calcular_distancia(&A);
    double area = pow(p * (p - lado1) * (p - lado2) * (p - lado3), 0.5);
    return area;
}

double Triangulo::calcular_perimetro() {
    double lado1 = A.calcular_distancia(&B);
    double lado2 = B.calcular_distancia(&C);
    double lado3 = C.calcular_distancia(&A);
    return lado1 + lado2 + lado3;
}

int Triangulo::comparar_area(Triangulo *triangulo) {
    double areaTri1 = calcular_area();
    double areaTri2 = triangulo->calcular_area();
    if(areaTri1 < areaTri2) return -1;
    if(int(areaTri1 * 100) == int(areaTri2 * 100)) return 0;
    return 1;
}