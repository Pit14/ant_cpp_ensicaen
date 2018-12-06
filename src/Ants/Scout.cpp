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

void Scout::move(Coord c) {
    current_coord = c;
}

void Scout::update(){

}
void Scout::eat(){
    cout << "scout mange" << nest->getFood() << endl;
}
