//
// Created by edgar on 28/11/2018.
//


#include "../../include/Ants/BadAnt.h"
#include "../../include/Ants/Nest.h"
#include "../../include/Map/Grid.h"


using namespace DATA;
using namespace FOODS;
using namespace std;

/***
 * Constuctor of bad ant, it will decide which side they will spawned
 * @param *n is a references to the nest, it helps to get grid data
 */
BadAnt::BadAnt(Nest *n):
        Ant(*n)
{
    nest = n;
    Cell ** m = nest->getMap();
    int x,y;
    bool spawned = false;

    int side_spawn = rand() % 4;
    while (!spawned) {
        switch(side_spawn) {

            case 0:
            x = 0;
            current_coord.setX(x);
            y = rand() % HEIGHT;
            if (m[x][y].getState() != BLOCKED) {
                current_coord.setY(y);
                spawned = true;
                break;
            }

            case 1:
                y = 0;
                current_coord.setY(y);
                x = rand() % WIDTH;
                if (m[x][y].getState() != BLOCKED) {
                    current_coord.setX(x);
                    spawned = true;
                    break;
                }

            case 2:
                x = WIDTH-1;
                current_coord.setX(x);
                y = rand() % HEIGHT;
                if (m[x][y].getState() != BLOCKED) {
                    current_coord.setY(y);
                    spawned = true;
                    break;
                }

            case 3:
                y = HEIGHT-1;
                current_coord.setY(y);
                x = rand() % WIDTH;
                if (m[x][y].getState() != BLOCKED) {
                    current_coord.setX(x);
                    spawned = true;
                    break;
                }
        }
    }
    path_to_nest.push(current_coord);
}



/***
 * delete the ant
 */
void BadAnt::die() {
    nest->kill_ant(this);
}
/***
 * set the current position of the ant and add the last position in a container
 * @param x
 * @param y
 */
void BadAnt::move(int x, int y) {
    current_coord.setX(x);
    current_coord.setY(y);

    path_to_nest.push(current_coord);
}


/***
 * Main function of badAnt, main skills of the ant should be here
 */
bool BadAnt::update(){

    setAge(getAge() + 1);

    if (getAge() > LIFE_EXPECTANCY) {
        die();
    }else{
                find_move();

    }
    return false;

}
/***
 * test if the choosen future position is available
 * @param x
 * @param y
 * @m array of the grid
 */
bool BadAnt::try_to_move(int x,int y, Cell ** m){

    if(!Grid::isOutOfLimit(x,y)) {
        if (m[x][y].getState() != BLOCKED ) {

            move(x, y);

            return true;
        }
    }
    return false;
}
/***
 * Use to clear the road to the spawn when the ant is returning home
 * @param i
 * @param l
 */
int BadAnt::get_last_doublon(int i, vector<Coord> l){
    Coord c = l[i];
    int last_doublon_index = -1;
    for(int j=i+1;j<l.size();j++){ // we are going through the vector to find another doublon
        if(l[j].getX() == c.getX() && l[j].getY() == c.getY()){ // Doublon ! we update the last index
            last_doublon_index = j;
        }
    }
    return last_doublon_index;
}


/***
 * the ant will find somewhere it can move. Randomly for the moment.
 */
void BadAnt::find_move() {
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
 * the ant has to eat to live
 */
bool BadAnt::eat(){ return true;}
