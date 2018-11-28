//
// Created by edgar on 28/11/2018.
//
using namespace std;

#ifndef C_ANT_H
#define C_ANT_H


#include "Coord.h"
#include <stack>

class Ant {
public:
    Ant(const Coord &current_coord, Coord *path_to_nest, int age);

    Ant(const Coord &current_coord, const stack<Coord> &path_to_nest, int age);

    virtual ~Ant();

private:
    Coord current_coord;
    std::stack<Coord> path_to_nest;
    int age;


};


#endif //C_ANT_H
