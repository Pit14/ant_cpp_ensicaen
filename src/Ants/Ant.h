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
    Ant(const Coord &current_coord, Coord *path_to_nest, int age);

    Ant(const Coord &current_coord, const stack<Coord> &path_to_nest, int age);

    virtual ~Ant();

protected:
    Coord current_coord;

private:
    std::stack<Coord> path_to_nest;
    int age;
    void die();


};


#endif //C_ANT_H
