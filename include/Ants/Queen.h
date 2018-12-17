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


class colony::Queen:public Ant {

public:
    Queen(Nest *n);

    virtual bool update();
    virtual bool eat();
    virtual void die();

    void give_birth();
};


#endif //C_QUEEN_H
