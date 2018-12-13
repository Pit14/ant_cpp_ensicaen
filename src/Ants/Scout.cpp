//
// Created by edgar on 29/11/2018.
//

#include "Scout.h"
#include "Nest.h"

Scout::Scout(Nest *n):
        Ant(*n)
{
    nest = n;
    current_coord.setY(round(HEIGHT/2));
    current_coord.setX(round(WIDTH/2));

    Cell ** m = nest->getMap();

   /* int cpti;
    int cptj;
    for(cpti=0;cpti<HEIGHT-1;cpti++){
        for(cptj=0;cptj<WIDTH-1;cptj++){
            cout << " " << m[cptj][cpti].getState();
        }
        cout << endl;
    }*/

}

/***
 * we call the kill_ant function from the nest to delete the ant.
 */
void Scout::die() {
    nest->kill_ant(this);
}

/***
 * the ant will find somewhere it can move. Randomly for the moment.
 */
void Scout::find_move() {
    Cell ** m = nest->getMap();

    bool has_moved = false;

    while(!has_moved) {

        int rand_dir = rand() % 8 +1;

        switch (rand_dir) {

            case 1 :// left
                has_moved = try_to_move(current_coord.getX() - 1, current_coord.getY() - 1, m);
                break;
            case 2 :
                has_moved = try_to_move(current_coord.getX(), current_coord.getY() - 1, m);
                break;
            case 3 :
                has_moved = try_to_move(current_coord.getX() + 1, current_coord.getY() - 1, m);
                break;
            case 4 :
                has_moved = try_to_move(current_coord.getX() - 1, current_coord.getY(), m);
                break;
            case 5 :
                has_moved = try_to_move(current_coord.getX() + 1, current_coord.getY(), m);
                break;
            case 6 :
                has_moved = try_to_move(current_coord.getX() - 1, current_coord.getY() + 1, m);
                break;
            case 7 :
                has_moved = try_to_move(current_coord.getX(), current_coord.getY() + 1, m);
                break;
            case 8 :
                has_moved = try_to_move(current_coord.getX() + 1, current_coord.getY() + 1, m);
                break;
        }

    }
}

/***
 * will check if the coord is off limit, and if it's not, the ant will move on the cell corresponding
 * @param x : coord to wich you want to move
 * @param y : coord to wich you want to move
 * @param m : pointer pointing at the map
 */
bool Scout::try_to_move(int x,int y, Cell ** m){

    if(!Grid::isOutOfLimit(x,y)) {
        if (m[x][y].getState() != BLOCKED) {
            move(x,y);
            return true;
        }
    }
    return false;
}

/***
 * We unfg the cell if it hasn't already be unfogged
 * @param x : coord of the cell to unfog
 * @param y : coord of the cell to unfog
 */
void Scout::discoverMap(int x, int y) {
    Cell ** m = nest->getMap();
    if ( !Grid::isOutOfLimit(x,y) && m[x][y].getHide())
        m[x][y].setVisible();
}

/***
 * We make visible all the nearby cell to the ant.
 * @param x : x coord of the ant
 * @param y : y coord of the ant
 */
void Scout::discoverMapLoop(int x,int y) {

    discoverMap(x-1,y);
    discoverMap(x-1,y-1);
    discoverMap(x-1,y+1);

    discoverMap(x,y);
    discoverMap(x,y+1);
    discoverMap(x,y-1);

    discoverMap(x+1,y);
    discoverMap(x+1,y+1);
    discoverMap(x+1,y-1);
}

/***
 * The ant will move on the cell corresponding to the coord passed in argument.
 * The scout ant will also discover what's under the fog.
 * @param c : the coord we want the ant to move on.
 */
void Scout::move(int x, int y) {
    current_coord.setX(x);
    current_coord.setY(y);
    discoverMapLoop(current_coord.getX(), current_coord.getY());
}

/***
 * function that will be called each day by each ant, they will just do their action for the day :
 * aging, eating, moving, dying....
 */
void Scout::update(){
    setAge(getAge() + 1);

    if (getAge() > LIFE_EXPECTANCY) {
        die();
    }else{
        cout << "debut scout" << endl;
        eat(); // we eat wether we're minor or major
        cout << "fin scout" << endl;


        if(!is_minor) { // is not minor
            find_move();
        }else{ // is minor
            if(getAge()>=SCOUT_MINOR_DAY){
                setIs_minor(false);
            }
        }
    }
}

/***
 * the ant will eat his daily food dose needed to survive.
 * If there's not enough food in the nest, the ant will simply die.
 */
bool Scout::eat(){
    if(nest->getFood()<DAILY_FOOD_CONSUMPTION_ANT){ // not enough food, ant die.
        die();
        return false;
    }else{
        nest->setFood(nest->getFood()-DAILY_FOOD_CONSUMPTION_ANT);
        return true;
    }
}

/***
 * The ant isn't minor anymore, so we turn her is_minor boolean attribute to false.
 * @param is_minor
 */
void Scout::setIs_minor(bool is_minor) {
    Scout::is_minor = is_minor;
}
