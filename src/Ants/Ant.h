//
// Created by edgar on 28/11/2018.
//
using namespace std;

#ifndef C_ANT_H
#define C_ANT_H


#include "../Map/Coord.h"
#include "../Ants/Nest.h"
#include <stack>

class Ant {

public:
    Ant(Coord = {0,0}, int = 0);

    virtual ~Ant();

    virtual void update() = 0;
    virtual void eat() = 0;
    virtual void die() = 0;


protected:
    Coord current_coord;
    std::stack<Coord> path_to_nest;
    int age;
    Nest nest;




};


#endif //C_ANT_H