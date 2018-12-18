//
// Created by Jerome on 28/11/2018.
//


#include <iostream>
#include "../../include/Map/Cell.h"
#include "../../include/Map/Coord.h"


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

int Cell::getCurrentAnts() {
    return current_ants;
}

void Cell::addAnt(){
    current_ants++;
}

void Cell::takeAnt(){
    current_ants--;
}


void Cell::setValue( Coord* current_coords, float foods, int pheros, int currents_ants) {
    current_coord = current_coords;
    food = foods;
    phero = pheros;
    current_ants = currents_ants;
    hide = true;

};