//
// Created by edgar on 28/11/2018.
//
using namespace std;

#ifndef C_SOLDIER_H
#define C_SOLDIER_H


#include <vector>
#include "Ant.h"
#include "BadAnt.h"
#include "../Map/Cell.h"

class Soldier: public Ant {

protected:

    int when_return_nest;
    int day_without_nest;

public:
    void kill(BadAnt b);
    virtual void die();
    void move(int x, int y);
    virtual bool eat();
    virtual bool update();
    void move_back_to_nest(int x, int y);
    bool try_to_move(int x,int y, Cell ** m);
    void clear_path_to_nest();
    int get_last_doublon(int i, vector<Coord> l);
    void find_move();
    Soldier(Nest *n);
};


#endif //C_SOLDIER_H
