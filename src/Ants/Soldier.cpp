//
// Created by edgar on 28/11/2018.
//
using namespace std;

#include "Soldier.h"
#include "BadAnt.h"
#include "Nest.h"

Soldier::Soldier(Nest *n):
        Ant(*n)
{
    nest = n;
    cout << "instanciation soldier" << endl;
}

void Soldier::die() {

}

void Soldier::move(Coord c) {
    current_coord = c;
}

void Soldier::update(){

}
void Soldier::eat(){
    cout << "soldier mange" << nest->getFood() << endl;
}

void Soldier::kill(BadAnt b) {
    b.die();
}
