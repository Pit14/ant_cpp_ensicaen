//
// Created by edgar on 29/11/2018.
//

#ifndef C_QUEEN_H
#define C_QUEEN_H


#include <iostream>
#include "Ant.h"
#include "Soldier.h"
#include "Worker.h"
#include "Scout.h"

class Queen:public Ant {

public:
    Queen(Nest *n);

    virtual void update();
    virtual void eat();
    virtual void die();

    void give_birth();
    //Coord position;
};


#endif //C_QUEEN_H
