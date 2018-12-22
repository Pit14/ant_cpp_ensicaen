//
// Created by Jerome on 28/11/2018.
//


#include <iostream>
#include "../../include/Map/Cell.h"
#include "../../include/Map/Coord.h"


Cell::Cell()= default;

Cell::~Cell() = default;
void Cell::TakeFood() {
    food--;
    if(food == 0){
        setState(FREE);
    }
}

/***
 * Take food on the cell when ant is on the case
 * @param value
 */
void Cell::EatFood( int value) {
    food = food - value;

}

/***
 * Modify the state of the cell, depending if it is a rock, food or colony part
 * @param states
 */
void Cell::setState(state_cell states) {
    state = states;
}

/***
 * Change the boolean which says if the case is in fog or if it has been discovered by scout
 */
void Cell::setVisible() {
    hide = false;
}

/***
 * return a boolean that says if the cell is in fog or not
 */
bool Cell::getHide(){
    return hide;
}

/***
 * Modify quantity of food in the case ( for the generation)
 * @param foods
 */
void Cell::setFood(float foods) {
    food = foods;
}

/***
 * return the quantity of food on the case
 */
float Cell::getFood() {
    return food;
}

/***
 * return the state of the case, if it is a rock, food or other...
 */
state_cell Cell::getState(){
    return state;
}

/***
 * return the count of ants that are currenctly located on the case
 */
int Cell::getCurrentAnts() {
    return current_ants;
}
/***
 * add one ant to the count of the cell
 */
void Cell::addAnt(){
    current_ants++;
}

/***
 * Reduce by one the count of the ant on the cell
 */
void Cell::takeAnt(){
    current_ants--;
}

/***
 * initialise the data of the cell after creation
 * @param current_coords
 * @param foods
 * @param pheros
 * @param currents_coords
 *
 */
void Cell::setValue( Coord* current_coords, float foods, int pheros, int currents_ants) {
    current_coord = current_coords;
    food = foods;
    phero = pheros;
    current_ants = currents_ants;
    hide = true;

};