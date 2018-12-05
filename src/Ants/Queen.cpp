//
// Created by edgar on 29/11/2018.
//

#include "Queen.h"

Queen::Queen():
    Ant()
{

}

void Queen::update(){
    std::cout << "test" << std::endl;

    eat();

    if(this->age > 0){
        give_birth();
    }else{
        // nouvelle fourmi scout        this.nest.ants.push();
    }

}

void Queen::eat(){
    if(this->nest.food < 0.01){
        this->nest.food -= 0.01;
    }else{
        this->die();
    }
}

void Queen::die(){
    //end of simulation
}

void Queen::give_birth(){

    int random = rand() % 100 + 1;

    if(random <= 80) {
        //this->nest.ants
        //return new Worker();
    } else if(random <= 95) {
       // return new Soldier(new Coord(0,0),new Coord*,0,0);
    }else{
      //  return new Scout();
    }

}

