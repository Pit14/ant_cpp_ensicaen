//
// Created by edgar on 28/11/2018.
//
using namespace std;

#ifndef C_ANT_H
#define C_ANT_H


#include "../Map/Coord.h"
#include <stack>
#include <cmath>
#include "../../src/define.h"
using namespace WIND;

class Nest;

class Ant {

public:
    Ant(Nest n, Coord = {(int) round(HEIGHT/2),(int) round(WIDTH/2)}, int = 0);
    Coord getCoord();

    virtual ~Ant();

    int getAge() const;

    void setAge(int age);

    virtual bool update() = 0;
    virtual bool eat() = 0;
    virtual void die() = 0;


protected:
    Coord current_coord;
    std::stack<Coord> path_to_nest;
    int age;
    Nest *nest;




};


#endif //C_ANT_H
