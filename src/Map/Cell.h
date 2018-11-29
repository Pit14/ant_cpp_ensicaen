//
// Created by Jerome on 28/11/2018.
//

#ifndef C_CELL_H
#define C_CELL_H


#include "Coord.h"

typedef enum {
    FREE, COLONY, BLOCKED
} state_cell;
class Cell {



public:

    Cell();
    void TakeFood();
    void EatFood(int value);
    friend void setValue(Cell &, Coord* current_coord, float food, int phero, int current_ants,state_cell state);


    Coord* current_coord;
    float food;
    int phero;
    int current_ants;
    state_cell state;

};


#endif //C_CELL_H
