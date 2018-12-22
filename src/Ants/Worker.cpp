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
    is_carriyng_food = false;
    current_coord.setY(round(HEIGHT/2));
    current_coord.setX(round(WIDTH/2));

    path_to_nest.push(current_coord);
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

    if(!is_carriyng_food){
        //cout << x << " " << y << endl;
       // Coord c = Coord(x,y);
        //cout << c.getX() << " "<< c.getY() << endl;
        path_to_nest.push(current_coord);
    }else if(is_carriyng_food && !path_to_nest.empty()){
      //  path_to_nest.pop();
    }

}

void Worker::move_back_to_nest(int x, int y){
    current_coord.setX(x);
    current_coord.setY(y);
    //cout << current_coord.getX() << " " << current_coord.getY() << endl;
    path_to_nest.pop();
}

/***
 * function that will be called each day by each ant, they will just do their action for the day :
 * aging, eating, moving, carrying food, dying....
 */
void Worker::update(){
    setAge(getAge() + 1);
    int x,y;

    if (getAge() > LIFE_EXPECTANCY) {
        die();
    }else{

         if(eat()){ // we eat wether we're minor or major

             if(!is_minor) { // is not minor
                 if(!is_carriyng_food){ // if we are not carrying food we move.
                     find_move();
                 }else{ // if we are carrying food, we're going back to the nest by following the path to nest
                     if(!path_to_nest.empty()){
                         //cout << "not empty" << endl;

                         //find_move();
                         move_back_to_nest(path_to_nest.top().getX(),path_to_nest.top().getY());

                        // try_to_move();
                     }else{ // we're on the nest
                         //find_move();

                         path_to_nest.push(current_coord);
                        //cout << "food deposit" << endl;

                         is_carriyng_food = false;
                         nest->setFood(nest->getFood()+1);
                     }
                 }
             }else{ // is minor
                 if(getAge()>= WORKER_MINOR_DAY){
                     setIs_minor(false);
                 }
             }

         }


    }

}


/***
 * will check if the coord is not off limit, and if it's already have been discovered by a scout,
 * if so, the ant will move on the cell corresponding
 * @param x : coord to wich you want to move
 * @param y : coord to wich you want to move
 * @param m : pointer pointing at the map
 */
bool Worker::try_to_move(int x,int y, Cell ** m){

    if(!Grid::isOutOfLimit(x,y)) {
        if (m[x][y].getState() != BLOCKED && !m[x][y].getHide() ) {

            if(m[x][y].getState() == FOOD){


                is_carriyng_food = true;
                m[x][y].TakeFood();
               // cout << "SIZE BEFORE CLEARING : " <<  path_to_nest.size() << endl;

                clear_path_to_nest();
                //cout << "SIZE AFTER CLEARING : " <<  path_to_nest.size() << endl;

            }
            move(x, y);


            return true;
        }
    }
    return false;
}

void Worker::clear_path_to_nest(){
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

int Worker::get_last_doublon(int i, vector<Coord> l){
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
bool Worker::eat(){
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
void Worker::setIs_minor(bool is_minor) {
    Worker::is_minor = is_minor;
}