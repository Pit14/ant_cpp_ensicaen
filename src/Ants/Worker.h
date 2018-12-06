//
// Created by edgar on 28/11/2018.
//
using namespace std;

#ifndef C_WORKER_H
#define C_WORKER_H


#include "Ant.h"

class Worker: public Ant {

protected:
    bool is_minor;
    bool is_carriyng_food;
    int pheromone = 500;

public:
    void pick_up_food();
    void die();
    void drop_food();
    void move(Coord c);
    void live();

};


#endif //C_WORKER_H
