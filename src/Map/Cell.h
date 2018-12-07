//
// Created by Jerome on 28/11/2018.
//

#ifndef C_CELL_H
#define C_CELL_H


#include "Coord.h"
#include "../define.h"

class Cell {



public:

    Cell();
    void TakeFood();
    void EatFood(int value);
    friend void setValue(Cell &, Coord* current_coord, float food, int phero, int current_ants,state_cell state);
    state_cell getState();
    void setState(state_cell states);
    void setFood(float foods);
    void setVisible();

protected:
    Coord* current_coord;
    float food;
    int phero;
    int current_ants;
    state_cell state;
    bool hide;

};


#endif //C_CELL_H
