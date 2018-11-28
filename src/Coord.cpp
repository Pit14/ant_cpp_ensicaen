//
// Created by edgar on 28/11/2018.
//
using namespace std;

#include "Coord.h"

Coord::Coord(int x, int y) : x(x), y(y) {}

Coord::~Coord() {}

int Coord::getX() const {
    return x;
}

void Coord::setX(int x) {
    Coord::x = x;
}

int Coord::getY() const {
    return y;
}

void Coord::setY(int y) {
    Coord::y = y;
}
