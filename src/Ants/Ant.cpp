//
// Created by edgar on 28/11/2018.
//
using namespace std;

#include "Ant.h"
#include "Nest.h"

Ant::~Ant() {

}

Ant::Ant(Coord current_coord, int age) : current_coord(current_coord),
                                                age(age) {}