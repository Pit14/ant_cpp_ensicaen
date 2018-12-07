//
// Created by edgar on 29/11/2018.
//

#ifndef C_SCOUT_H
#define C_SCOUT_H


#include "Ant.h"

class Scout: public Ant {

public:
    virtual void die();
    void move(Coord c);
    void find_move();
    virtual void eat();
    virtual void update();
    Scout(Nest *n);

};


#endif //C_SCOUT_H
