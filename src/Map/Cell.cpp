//
// Created by Jerome on 28/11/2018.
//


#include "Cell.h"
#include "Coord.h"


Cell::Cell()= default;

void Cell::TakeFood() {
    food--;
}

void Cell::EatFood( int value) {
    food = food - value;

}
void Cell::setState(state_cell states) {
    state = states;
}

void Cell::setVisible() {
    hide = false;
}
void Cell::setFood(float foods) {
    food = foods;
}
state_cell Cell::getState(){
    return state;
}
void setValue(Cell &c, Coord* current_coords, float foods, int pheros, int currents_ants,state_cell states) {
    c.current_coord = current_coords;
    c.food = foods;
    c.phero = pheros;
    c.current_ants = currents_ants;
    c.state = states;
    c.hide = true;
};