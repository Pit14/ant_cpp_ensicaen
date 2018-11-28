//
// Created by Jerome on 28/11/2018.
//

#include "Cell.h"
#include "Coord.h"


Cell::Cell( Coord &current_coord, float food, int phero, int current_ants, state_cell state) : current_coord(current_coord), food(food), phero(phero), current_ants(current_ants), state(state){}

void Cell::TakeFood() {
    food--;
}

void Cell::EatFood( int value) {
    food = food - value;

}