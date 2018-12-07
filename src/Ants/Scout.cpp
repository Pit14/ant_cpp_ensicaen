//
// Created by edgar on 29/11/2018.
//

#include "Scout.h"

#include "Nest.h"

Scout::Scout(Nest *n):
        Ant(*n)
{
    nest = n;
    cout << "instanciation scout" << endl;

}

void Scout::die() {

}

void Scout::find_move() {
    Cell ** m = nest->getMap();
    int rand_dir = rand() % 8 +1;
    cout <<  "Random : " << rand_dir << endl;

    if(rand_dir == 1) { // left up
        Coord *c = new Coord(current_coord.getX()-1, current_coord.getY()-1);
        if(m[c->getY(),c->getY()]->state == FREE){
            move(*c);
        }
    }


}

void Scout::move(Coord c) {
    current_coord = c;
    cout <<  "scout moved !" << endl;

}

void Scout::update(){
    // eat();
    find_move();
}
void Scout::eat(){
    cout << "scout mange" << nest->getFood() << endl;
}
