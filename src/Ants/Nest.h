//
// Created by Jerome on 05/12/2018.
//

#ifndef PROJECT_NEST_H
#define PROJECT_NEST_H

#include <list>
#include "Ant.h"

class Nest {

protected :
    void Simulate();
    list<Ant*> ants;
    double food;

public:

    Nest();

    void setAnts(const list<Ant*> &ants);

    void setFood(double food);

    const list<Ant *> &getAnts() const;

    double getFood() const;
};


#endif //PROJECT_NEST_H
