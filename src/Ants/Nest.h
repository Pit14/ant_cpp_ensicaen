//
// Created by Jerome on 05/12/2018.
//

#ifndef PROJECT_NEST_H
#define PROJECT_NEST_H

#include <list>
#include <iostream>
#include "Ant.h"

class Nest {

protected :
    list<Ant*> ants;
    double food;

public:

    Nest();

   void update_nest();

    void setAnts(const list<Ant*> &ants);

    void setFood(double food);

    const list<Ant *> &getAnts() const;

    double getFood() const;

    void add_ant(Ant* a);
};


#endif //PROJECT_NEST_H
