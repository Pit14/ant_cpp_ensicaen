//
// Created by edgar on 28/11/2018.
//
using namespace std;

#include "../../include/Ants/Ant.h"
#include "../../include/Ants/Nest.h"

Ant::~Ant() {

}

Ant::Ant(Nest n, Coord current_coord, int age) : current_coord(current_coord),age(age),nest(&n) {}


Coord Ant::getCoord() {
    return current_coord;
}

int Ant::getAge() const {
    return age;
}

void Ant::setAge(int age) {
    Ant::age = age;
}
