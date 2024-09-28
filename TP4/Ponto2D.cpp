#include "Ponto2D.hpp"
#include <cmath>

Ponto2D::Ponto2D(double x, double y) {
    _x = x;
    _y = y;
}

double Ponto2D::calcular_distancia(Ponto2D* ponto) {
    double distX = _x - ponto->_x;
    double distY = _y - ponto->_y;
    return pow(pow(distX, 2) + pow(distY, 2), 0.5);
}