//
// Created by edgar on 28/11/2018.
//
using namespace std;

#include "Ant.h"

Ant::~Ant() {

}

Ant::Ant(const Coord &current_coord, const stack<Coord> &path_to_nest, int age) : current_coord(current_coord),
                                                                                  path_to_nest(path_to_nest),
                                                                                  age(age) {}
