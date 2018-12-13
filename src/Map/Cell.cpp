//
// Created by Jerome on 28/11/2018.
//


#include "Cell.h"
#include "Coord.h"


Cell::Cell()= default;

void Cell::TakeFood() {
    food--;
    if(food == 0){
        setState(FREE);
    }
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

bool Cell::getHide(){
    return hide;
}
void Cell::setFood(float foods) {
    food = foods;
}

float Cell::getFood() {
    return food;
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