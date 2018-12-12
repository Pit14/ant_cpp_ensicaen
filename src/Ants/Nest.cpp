//
// Created by Jerome on 05/12/2018.
//

#include "Nest.h"
#include "Queen.h"

Nest::Nest(Cell ** m) {
    food = INITIAL_FOOD_ON_NEST;
    map = m;
    Queen *queen = new Queen(this);
    ants.push_back(queen);
}

void Nest::update_nest() {
    for(std::list<Ant*>::iterator it = ants.begin(); it!=ants.end(); ++it)
    {
        (*it)->update();
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

void Nest::add_ant(Ant *a) {
    ants.push_back(a);
}

Cell **Nest::getMap() const {
    return map;
}

void Nest::setMap(Cell **map) {
    Nest::map = map;
}

void Nest::kill_ant(Ant *ant) {
    ants.remove(ant);
    delete ant;
}
