//
// Created by Jerome on 05/12/2018.
//

#include "Nest.h"
#include "Queen.h"

Nest::Nest() {

    food = 2;

}

void Nest::update() {
//    Queen *queen = new Queen();
//    ants.push_back(queen);
//    for(std::list<Ant*>::iterator it = ants.begin(); it!=ants.end(); ++it)
//    {
//        (*it)->update();
//    }

std::cout << "cc" << endl;
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

void Nest::add_ant(Ant *a) {
    ants.push_back(a);
}
