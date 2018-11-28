//
// Created by edgar on 28/11/2018.
//

#ifndef C_WORKER_H
#define C_WORKER_H


#include "Ant.h"

class Worker: public Ant {

    bool is_minor;
    bool is_carriyng_food;
    int pheromone = 500;

    void pick_up_food();
    void die();
    void drop_food();
    void move(Coord c);

};


#endif //C_WORKER_H
