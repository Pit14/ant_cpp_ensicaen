//
// Created by edgar on 28/11/2018.
//
using namespace std;

#ifndef C_ANT_H
#define C_ANT_H


#include "../Map/Coord.h"
#include <stack>

class Ant {
public:

    virtual ~Ant();

protected:
    Coord current_coord;
    std::stack<Coord> path_to_nest;
    int age;


private:
    void die();


};


#endif //C_ANT_H
