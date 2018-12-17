//
// Created by Jerome on 05/12/2018.
//

#ifndef PROJECT_NEST_H
#define PROJECT_NEST_H

#include <list>
#include <iostream>
#include "Ant.h"
#include "../Map/Cell.h"

class Nest {

protected :
    list<Ant*> ants;
    double food;
    Cell ** map;

public:

    Nest(Cell ** map);

   bool update_nest();

    void setAnts(const list<Ant*> &ants);

    void setFood(double food);

    const list<Ant *> &getAnts() const;

    double getFood() const;

    void add_ant(Ant* a);

    Cell **getMap() const;

    void setMap(Cell **map);

    void kill_ant(Ant *ant);
};


#endif //PROJECT_NEST_H
