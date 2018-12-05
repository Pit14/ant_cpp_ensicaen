//
// Created by Jerome on 05/12/2018.
//

#include "Nest.h"

Nest::Nest() {

    food = 2;

}

void Nest::Simulate() {
    for(list<Ant*>::iterator it = ants.begin(); it!=ants.end(); ++it)
    {

    }
}

const list<Ant *> &Nest::getAnts() const {
    return ants;
}

double Nest::getFood() const {
    return food;
}

void Nest::setAnts(const list<Ant *> &ants) {
    Nest::ants = ants;
}

void Nest::setFood(double food) {
    Nest::food = food;
}
