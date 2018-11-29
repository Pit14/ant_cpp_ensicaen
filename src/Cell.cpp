//
// Created by Jerome on 28/11/2018.
//

#include "Cell.h"
#include "Coord.h"


Cell::Cell(){}

void Cell::TakeFood() {
    food--;
}

void Cell::EatFood( int value) {
    food = food - value;

}

void Cell::setValue(Coord* current_coords, float foods, int pheros, int currents_ants,state_cell states) {
    current_coord = current_coords;
    food = foods;
    phero = pheros;
    current_ants = currents_ants;
    state = states;
};