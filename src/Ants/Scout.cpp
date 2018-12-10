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
    current_coord.setY(round(HEIGHT/2));
    current_coord.setX(round(WIDTH/2));

    Cell ** m = nest->getMap();

    int cpti;
    int cptj;
    for(cpti=0;cpti<HEIGHT-1;cpti++){
        for(cptj=0;cptj<WIDTH-1;cptj++){
            cout << " " << m[cptj][cpti].getState();
        }
        cout << endl;
    }

}

void Scout::die() {

}

void Scout::find_move() {
    Cell ** m = nest->getMap();
    int rand_dir = rand() % 8 +1;
    //cout <<  "Random : " << rand_dir << endl;

    Coord *c;// = new Coord(1,1);


    switch(rand_dir) { // left

        case 1 :
            c->setY(current_coord.getY() - 1);
            c->setX(current_coord.getX() - 1);

            //cout <<  "m15 : " << m[15,15]->getState() << endl;

            cout << m[c->getX(), c->getY()]->getState() << endl;


            if (m[c->getX(), c->getY()]->getState() == FREE) {
                //cout <<  "before move : " << endl;
                //            cout <<  "get y current_coord : " << ( current_coord.getY()) << endl;
                //            cout <<  "get x current coord : " << current_coord.getX() << endl;
                //
                //            cout <<  "get y c : " << c->getY() << endl;
                //            cout <<  "get x c : " << c->getX() << endl;

                move(*c);
            }
            break;
        case 2 :
            c->setY(current_coord.getY() - 1);
            c->setX(current_coord.getX());
            if (m[c->getX(), c->getY()]->getState() == FREE) {
                move(*c);
            }
            break;
        case 3 :
            c->setY(current_coord.getY() - 1);
            c->setX(current_coord.getX()+1);
            if (m[c->getX(), c->getY()]->getState() == FREE) {
                move(*c);
            }
            break;
        case 4 :
            c->setY(current_coord.getY());
            c->setX(current_coord.getX()-1);
            if (m[c->getX(), c->getY()]->getState() == FREE) {
                move(*c);
            }
            break;
        case 5 :
            c->setY(current_coord.getY());
            c->setX(current_coord.getX()+1);
            if (m[c->getX(), c->getY()]->getState() == FREE) {
                move(*c);
            }
            break;
        case 6 :
            c->setY(current_coord.getY()+1);
            c->setX(current_coord.getX()-1);
            if (m[c->getX(), c->getY()]->getState() == FREE) {
                move(*c);
            }
            break;
        case 7 :
            c->setY(current_coord.getY() +1);
            c->setX(current_coord.getX());
            if (m[c->getX(), c->getY()]->getState() == FREE) {
                move(*c);
            }
            break;
        case 8 :
            c->setY(current_coord.getY() +1);
            c->setX(current_coord.getX()+1);
            if (m[c->getX(), c->getY()]->getState() == FREE) {
                move(*c);
            }
            break;
    }

}

void Scout::setC(Coord *c,int x,int y){
    c->setY(y);
    c->setX(x);
}

void Scout::move(Coord c) {
    current_coord.setX(c.getX());
    current_coord.setY(c.getY());
    cout <<  "scout moved !" << endl;

}

void Scout::update(){
    // eat();
    find_move();
}
void Scout::eat(){
    cout << "scout mange" << nest->getFood() << endl;
}
