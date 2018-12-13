//
// Created by edgar on 28/11/2018.
//
using namespace std;

#ifndef C_WORKER_H
#define C_WORKER_H


#include "Ant.h"
#include "../Map/Grid.h"


class Worker: public Ant {

protected:
    bool is_minor;
    bool is_carriyng_food;
    int pheromone = 500;

public:
    void setIs_minor(bool is_minor);
    void find_move();
    bool try_to_move(int x, int y,Cell ** m);
    void clear_path_to_nest();
    void pick_up_food();
    virtual void die();
    void drop_food();
    void move(int x, int y);
    virtual void eat();
    virtual void update();
    Worker(Nest *n);


};


#endif //C_WORKER_H
