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
    Cell( Coord &current_coord, float food, int phero, int current_ants, state_cell state);
    Cell(){};
    void TakeFood();
    void EatFood(int value);
    void setValue(Coord &current_coord, float food, int phero, int current_ants,state_cell state);

private:
    Coord current_coord;
    int food;
    int phero;
    int current_ants;
    state_cell state;

};


#endif //C_CELL_H
