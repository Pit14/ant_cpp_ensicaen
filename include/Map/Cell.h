//
// Created by Jerome on 28/11/2018.
//

#ifndef C_CELL_H
#define C_CELL_H


#include "Coord.h"
#include "../../src/define.h"

class Cell {



public:

    Cell();
    virtual ~Cell();
    void TakeFood();
    void EatFood(int value);
    void setValue( Coord* current_coord, float food, int phero, int current_ants);
    state_cell getState();
    void setState(state_cell states);
    void setFood(float foods);
    float getFood();
    void setVisible();
    bool getHide();
    int getCurrentAnts();
    void addAnt();
    void takeAnt();

protected:
    Coord* current_coord;
    float food;
    int phero;
    int current_ants;
    state_cell state;
    bool hide;

};


#endif //C_CELL_H
