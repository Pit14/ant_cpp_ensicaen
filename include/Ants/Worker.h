//
// Created by edgar on 28/11/2018.
//
using namespace std;

#ifndef C_WORKER_H
#define C_WORKER_H


#include "../../include/Ants/Ant.h"
#include "../Map/Grid.h"


class colony::Worker: public Ant {

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
    void move_back_to_nest(int x, int y);
    virtual bool eat();
    virtual bool update();
    Worker(Nest *n);
    int get_last_doublon(int i, vector<Coord> l);


};


#endif //C_WORKER_H
