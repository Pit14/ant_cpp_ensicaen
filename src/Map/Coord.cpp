//
// Created by edgar on 28/11/2018.
//
using namespace std;

#include "../../include/Map/Coord.h"

Coord::Coord(int x, int y) {}

Coord::~Coord() = default;

/***
 * return the x-position  of the cell
 */
int Coord::getX() const {
    return x;
}
/***
 * Modify x-position of the cell
 * @param x
 */
void Coord::setX(int x) {
    Coord::x = x;
}

/***
 * return the y-position of the cell
 */
int Coord::getY() const {
    return y;
}

/***
 * Modify the y-position of the cell
 * @param y
 */
void Coord::setY(int y) {
    Coord::y = y;
}
