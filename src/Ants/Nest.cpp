//
// Created by Jerome on 05/12/2018.
//

#include "../../include/Ants/Nest.h"
#include "../../include/Ants/Queen.h"
using namespace FOODS;

Nest::Nest(Cell ** m) {
    food = INITIAL_FOOD_ON_NEST;
    map = m;
    Queen *queen = new Queen(this);
    ants.push_back(queen);
}

/***
 * we call this function each day,
 * it will call the update function of each ant in the list of ant
 */
bool Nest::update_nest() {

    bool res;
    bool exit;
    for(std::list<Ant*>::iterator it = ants.begin(); it!=ants.end(); ++it)
    {
        res = (*it)->update();
        if (res == true)
            exit = true;
    }

    if (exit == true)
        return true;

    return false;
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

/***
 * Will kill an ant by removing it from the list of ant, and call the delete function of the ant.
 * @param ant
 */
void Nest::kill_ant(Ant *ant) {
    ants.remove(ant);
    delete ant;
}
