/**
 * Todas as tarefas deste exercicio devem ser feitas sobre esse arquivo.
 * Os metodos e operacoes marcados com a tag "TODO" devem ser editados.
 */

#include <iostream>
#include "polygon.h"

std::ostream& operator << (std::ostream &out, const Polygon &poly) {
  for (const Point& p: poly.limits) {
    out << " " << p;
  }
  return out;
}

std::vector<Point> deleteDuplicates(std::vector<Point> original) {
  int originalCounter = 0;
  int auxCounter = 0;
  int originalSize = original.size();
  std::vector<Point> resultVector;
  Point temp(original.at(0).x, original.at(0).y);
  resultVector.push_back(temp);
  for (originalCounter++; originalCounter < originalSize; originalCounter++) {
      auxCounter = originalCounter;
      bool isBegining = originalCounter != 0;
      bool isXTheSame = original.at(originalCounter).x != original.at(auxCounter - 1).x;
      bool isYTheSame = original.at(originalCounter).y != original.at(auxCounter - 1).y;
      if (isBegining && isXTheSame && isYTheSame) {
          resultVector.push_back(original.at(originalCounter));
      }
  }
  return resultVector;
}

std::vector<Point> orderedTwoPointToFourPoint(std::vector<Point> lhsNoDup) {
  double tamanhoBase = lhsNoDup.at(0).x - lhsNoDup.at(1).x;
  double tamanhoAltura = lhsNoDup.at(0).y - lhsNoDup.at(1).y;
  std::vector<Point> fourPointRectangle;
  if (tamanhoBase < 0 && tamanhoAltura < 0) {
    fourPointRectangle.push_back(lhsNoDup.at(0));
    Point topLeft(lhsNoDup.at(0).x, lhsNoDup.at(0).y - tamanhoAltura);
    fourPointRectangle.push_back(topLeft);
    fourPointRectangle.push_back(lhsNoDup.at(1));
    Point bottomRight(lhsNoDup.at(0).x - tamanhoBase, lhsNoDup.at(0).y);
    fourPointRectangle.push_back(bottomRight);
  }
  if (tamanhoBase > 0 && tamanhoAltura > 0) {
    fourPointRectangle.push_back(lhsNoDup.at(1));
    Point topLeft(lhsNoDup.at(0).x - tamanhoBase, lhsNoDup.at(0).y);
    fourPointRectangle.push_back(topLeft);
    fourPointRectangle.push_back(lhsNoDup.at(0));
    Point bottomRight(lhsNoDup.at(0).x, lhsNoDup.at(0).y - tamanhoAltura);
    fourPointRectangle.push_back(bottomRight);
  }
  if (tamanhoBase < 0 && tamanhoAltura > 0) {
    Point bottomLeft(lhsNoDup.at(0).x, lhsNoDup.at(0).y - tamanhoAltura);
    fourPointRectangle.push_back(bottomLeft);
    fourPointRectangle.push_back(lhsNoDup.at(0));
    Point topRight(lhsNoDup.at(0).x - tamanhoBase, lhsNoDup.at(0).y);
    fourPointRectangle.push_back(topRight);
    fourPointRectangle.push_back(lhsNoDup.at(1));
  }
  if (tamanhoBase > 0 && tamanhoAltura < 0) {
    Point bottomLeft(lhsNoDup.at(0).x - tamanhoBase, lhsNoDup.at(0).y);
    fourPointRectangle.push_back(bottomLeft);
    fourPointRectangle.push_back(lhsNoDup.at(1));
    Point topRight(lhsNoDup.at(0).x, lhsNoDup.at(0).y - tamanhoAltura);
    fourPointRectangle.push_back(topRight);
    fourPointRectangle.push_back(lhsNoDup.at(0));
  }
    return fourPointRectangle;
}

bool operator == (const Polygon &lhs, const Polygon &rhs) {
  std::vector<Point> pontosLhs(lhs);
  std::vector<Point> lhsNoDup = deleteDuplicates(pontosLhs);
  std::vector<Point> pontosRhs(rhs);
  std::vector<Point> rhsNoDup = deleteDuplicates(pontosRhs);
  int sizeLhsNoDup = lhsNoDup.size();
  int sizeRhsNoDup = rhsNoDup.size();
  if (sizeLhsNoDup != sizeRhsNoDup) return false;
  if (sizeLhsNoDup == 2) { 
    double tamanhoBase = lhsNoDup.at(0).x - lhsNoDup.at(1).x;
    double tamanhoAltura = lhsNoDup.at(0).y - lhsNoDup.at(1).y;
    if (tamanhoBase == 0 || tamanhoAltura == 0) return false;
    lhsNoDup = orderedTwoPointToFourPoint(lhsNoDup);
    rhsNoDup = orderedTwoPointToFourPoint(rhsNoDup);
  }
  sizeLhsNoDup = lhsNoDup.size();
  sizeRhsNoDup = rhsNoDup.size();
  int lhsCounter = 0;
  int rhsCounter = 0;
  // lhsIt leaves loop pointing to element of lhsNoDup that
  //is equal to the first element of rhsNoDup
  for (lhsCounter; lhsCounter < sizeLhsNoDup; lhsCounter) {
    bool isXEqual = lhsNoDup.at(lhsCounter).x == rhsNoDup.at(rhsCounter).x;
    bool isYEqual = lhsNoDup.at(lhsCounter).y == rhsNoDup.at(rhsCounter).y;
    if (isXEqual && isYEqual) break;
    return false;
  }
  // iterates through the rest of lhsNoDup (starting from
  //lhsIt + 1 -- see last notes) checking if its equal to
  //element of rhsNoDup (starting from first element + 1)
  // rhsIt leaves loop pointing to element of rhsNoDup that
  //is one element behind the element that is equal to the
  //first element of lhsNoDup
  for (lhsCounter++; lhsCounter < sizeLhsNoDup; lhsCounter++) {
    rhsCounter++;
    bool isXDifferent = rhsNoDup.at(rhsCounter).x != lhsNoDup.at(lhsCounter).x;
    bool isYDifferent = rhsNoDup.at(rhsCounter).y != lhsNoDup.at(lhsCounter).y;
    if (isXDifferent || isYDifferent) return false;
  }
  // iterates through the rest of rhsNoDup (starting from
  //where rhsIt left off on the last loop) checking if its equal to
  //element of lhsNoDup (starting from first element)
  lhsCounter = 0;
  for (rhsCounter++; rhsCounter < sizeRhsNoDup; rhsCounter++) {
    bool isXDifferent = rhsNoDup.at(rhsCounter).x != lhsNoDup.at(lhsCounter).x;
    bool isYDifferent = rhsNoDup.at(rhsCounter).y != lhsNoDup.at(lhsCounter).y;
    if (isXDifferent || isYDifferent) return false;
    lhsCounter++;
  }
  return true;
}

bool Point::contains(const Point& p) const {
  return p.x == this->x && p.y == this->y;
}

std::ostream& operator << (std::ostream &out, const Point &p) {
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}

bool RightRectangle::contains(const Point& p) const {
  // TODO: implement this method.
  std::vector<Point> orderedVector = orderedTwoPointToFourPoint(limits);
  bool isWithinXRange = orderedVector.at(0).x <= p.x && p.x <= orderedVector.at(2).x;
  bool isWithinYRange = orderedVector.at(0).y <= p.y && p.y <= orderedVector.at(2).y;
  if (isWithinXRange && isWithinYRange) return true;
  return false;
}

Point::Point(int xx, int yy): x(xx), y(yy) {
  // TODO: implement this method.
  limits.push_back(*this);
}

RightRectangle::RightRectangle(int x0, int y0, int x1, int y1) {
  // TODO: implement this method.
  Point p0(x0, y0);
  limits.push_back(p0);
  Point p1(x1, y1);
  limits.push_back(p1);
}
