//
// Created by edgar on 28/11/2018.
//
using namespace std;

#ifndef C_SOLDIER_H
#define C_SOLDIER_H


#include "Ant.h"
#include "BadAnt.h"

class Soldier: public Ant {

protected:
    bool is_returning_to_the_nest;

public:
    void kill(BadAnt b);
    virtual void die();
    void move(Coord c);
    virtual void eat();
    virtual void update();
    Soldier(Nest *n);
};


#endif //C_SOLDIER_H
