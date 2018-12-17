//
// Created by edgar on 28/11/2018.
//
#include <vector>
#include "../Map/Cell.h"
#include "Nest.h"

using namespace std;

#ifndef C_BADANT_H
#define C_BADANT_H


class BadAnt: public Ant {

public:

    virtual void die();
    void move(int x, int y);
    virtual bool eat();
    virtual bool update();
    bool try_to_move(int x,int y, Cell ** m);
    int get_last_doublon(int i, vector<Coord> l);
    void find_move();
    BadAnt(Nest *n);

};


#endif //C_BADANT_H
