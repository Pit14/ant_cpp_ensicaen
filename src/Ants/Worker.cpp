//
// Created by edgar on 28/11/2018.
//
using namespace std;

#include "Worker.h"
#include "Nest.h"

Worker::Worker(Nest *n):
        Ant(*n)
{
    nest = n;

    current_coord.setY(round(HEIGHT/2));
    current_coord.setX(round(WIDTH/2));

    cout << "instanciation Worker" << endl;

}

/***
 * we call the kill_ant function from the nest to delete the ant.
 * The worker ant will the food she is curently carrying
 */
void Worker::die() {
    if(is_carriyng_food){
        drop_food();
    }
    nest->kill_ant(this);
}

void Worker::pick_up_food() {
    is_carriyng_food = true;
}

void Worker::drop_food() {
    is_carriyng_food = false;
}

void Worker::move(int x, int y) {
    current_coord.setX(x);
    current_coord.setY(y);
}

/***
 * function that will be called each day by each ant, they will just do their action for the day :
 * aging, eating, moving, carrying food, dying....
 */
void Worker::update(){
    setAge(getAge() + 1);

    if (getAge() > LIFE_EXPECTANCY) {
        die();
    }else{
        eat(); // we eat wether we're minor or major

        if(!is_minor) { // is not minor
            find_move();
        }else{ // is minor
            if(getAge()>= WORKER_MINOR_DAY){
                setIs_minor(false);
            }
        }
    }
}


/***
 * will check if the coord is off limit, and if it's not, the ant will move on the cell corresponding
 * @param x : coord to wich you want to move
 * @param y : coord to wich you want to move
 * @param m : pointer pointing at the map
 */
bool Worker::try_to_move(int x,int y, Cell ** m){

    if(!Grid::isOutOfLimit(x,y)) {
        if (m[x][y].getState() != BLOCKED) {
            move(x,y);
            return true;
        }
    }
    return false;
}


/***
 * the ant will find somewhere it can move. Randomly for the moment.
 */
void Worker::find_move() {
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
 * the ant will eat his daily food dose needed to survive.
 * If there's not enough food in the nest, the ant will simply die.
 */
void Worker::eat(){
    if(nest->getFood()<DAILY_FOOD_CONSUMPTION_ANT){ // not enough food, ant die.
        die();
    }else{
        nest->setFood(nest->getFood()-DAILY_FOOD_CONSUMPTION_ANT);
    }
}

/***
 * The ant isn't minor anymore, so we turn her is_minor boolean attribute to false.
 * @param is_minor
 */
void Worker::setIs_minor(bool is_minor) {
    Worker::is_minor = is_minor;
}
