//
// Created by edgar on 29/11/2018.
//

#include "Queen.h"
#include "Nest.h"

Queen::Queen(Nest *n):
    Ant(*n)
{
    nest = n;
}

void Queen::update(){
//    std::cout << "test" << std::endl;
    eat();
//    std::cout << age << std::endl;

    if(age > 0){
       // give_birth();
    }else{
        nest->add_ant(new Scout(nest));
        nest->add_ant(new Scout(nest));
        nest->add_ant(new Scout(nest));
    }
    age++;
}

void Queen::eat(){
    //cout << "mange" << nest->getFood() << endl;

    if(nest->getFood() > 0.01){
         nest->setFood(nest->getFood()- 0.01);
    }else{
        this->die();
    }
}

void Queen::die(){
    //end of simulation
   // cout << "End simulation" << endl;

}

void Queen::give_birth(){

    int random = rand() % 100 + 1;

    if(random <= 80) {
        nest->add_ant(new Worker(nest));
    } else if(random <= 95) {
        nest->add_ant(new Soldier(nest));
    }else{
        nest->add_ant(new Scout(nest));
    }

}

