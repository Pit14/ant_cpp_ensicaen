//
// Created by edgar on 28/11/2018.
//
using namespace std;

#include "BadAnt.h"
#include "Nest.h"
#include "../Map/Grid.h"

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




void BadAnt::die() {
    nest->kill_ant(this);
}

void BadAnt::move(int x, int y) {
    current_coord.setX(x);
    current_coord.setY(y);

    path_to_nest.push(current_coord);
}

void BadAnt::move_back_to_nest(int x, int y){
    current_coord.setX(x);
    current_coord.setY(y);
    //cout << current_coord.getX() << " " << current_coord.getY() << endl;
    path_to_nest.pop();
}


void BadAnt::update(){

    setAge(getAge() + 1);
    int x,y;

    if (getAge() > LIFE_EXPECTANCY) {
        die();
    }else{




          /*  if(day_without_nest >= when_return_nest) {

                if(!path_to_nest.empty()){
                    move_back_to_nest(path_to_nest.top().getX(),path_to_nest.top().getY());

                }else{

                    path_to_nest.push(current_coord);
                    day_without_nest = 0;

                }
            } else {*/

                find_move();

          //  }



    }

}

bool BadAnt::try_to_move(int x,int y, Cell ** m){

    if(!Grid::isOutOfLimit(x,y)) {
        if (m[x][y].getState() != BLOCKED ) {


            // si on fait demi-tour faire --> clear_path_to_nest();

            move(x, y);

      /*      if( day_without_nest > when_return_nest)
                clear_path_to_nest();*/


            return true;
        }
    }
    return false;
}

void BadAnt::clear_path_to_nest(){
    int size = path_to_nest.size();
    int i,d,j;
    std::vector<Coord> l;
//    cout << "debut clear" << endl;
//    cout << "path size debut : " << path_to_nest.size() << endl;
//
//    cout << path_to_nest.top().getX() << endl;
//    cout << path_to_nest.top().getY() << endl;

    for(i =0; i <size;i++){
        l.push_back(path_to_nest.top());
        path_to_nest.pop();
    }
//    cout << "path size : " << path_to_nest.size() << endl;
//    cout << "vector  size : " << l.size() << endl;
    size = l.size();


    for(i=0;i<size;i++){
        if(l[i].getX() != -1){
            d = get_last_doublon(i,l);
            if( d!= -1){
                for(j=i+1;j<=d;j++){
                    l[j].setX(-1); // this cell is redondant
                }
            }
        }

    }



    for(i =0; i <size;i++){
        if(l[size-i-1].getX() != -1){
            path_to_nest.push(l[size-i-1]);
        }
    }
//    cout << path_to_nest.top().getX() << endl;
//    cout << path_to_nest.top().getY() << endl;
//    cout << "fin clear" << endl;
}

int BadAnt::get_last_doublon(int i, vector<Coord> l){
    Coord c = l[i];
    int last_doublon_index = -1;
    for(int j=i+1;j<l.size();j++){ // we are going through the vector to find another doublon
        if(l[j].getX() == c.getX() && l[j].getY() == c.getY()){ // Doublon ! we update the last index
            last_doublon_index = j;
        }
    }
//    cout << "VECOTR : " << l[i].getX() << endl;
    // cout << "last doublon : " << last_doublon_index << endl;

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

bool BadAnt::eat(){
    if(nest->getFood()<DAILY_FOOD_CONSUMPTION_ANT){ // not enough food, ant die.
        die();
        return false;
    }else{
        nest->setFood(nest->getFood()-DAILY_FOOD_CONSUMPTION_ANT);
        return true;
    }
}
