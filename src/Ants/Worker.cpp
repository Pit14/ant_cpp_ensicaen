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
}

void Worker::die() {
    if(is_carriyng_food){
        drop_food();
    }
}

void Worker::pick_up_food() {
    is_carriyng_food = true;
}

void Worker::drop_food() {
    is_carriyng_food = false;
}

void Worker::move(Coord c) {
    current_coord = c;
}

void Worker::update(){
    if(!is_minor){

    }else{
        // Quand la fourmis est mineur ?
    }
}
void Worker::eat(){
    cout << "mange" << nest->getFood() << endl;
}
