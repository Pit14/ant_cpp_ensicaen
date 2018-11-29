//
// Created by edgar on 29/11/2018.
//

#ifndef C_QUEEN_H
#define C_QUEEN_H


#include "Ant.h"
#include "Soldier.h"
#include "Worker.h"
#include "Scout.h"

class Queen:public Ant {

public :
    Ant* give_birth();
};


#endif //C_QUEEN_H
