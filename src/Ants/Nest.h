//
// Created by Jerome on 05/12/2018.
//

#ifndef PROJECT_NEST_H
#define PROJECT_NEST_H

#include <list>
#include "Ant.h"

class Nest {

public:
    Nest();
protected :
    Simulate();
    list<Ant*> ants;
    double food;
};


#endif //PROJECT_NEST_H
