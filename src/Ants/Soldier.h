//
// Created by edgar on 28/11/2018.
//
using namespace std;

#ifndef C_SOLDIER_H
#define C_SOLDIER_H


#include "Ant.h"
#include "BadAnt.h"

class Soldier: public Ant {
    bool is_returning_to_the_nest;
    void kill(BadAnt b);;

};


#endif //C_SOLDIER_H
