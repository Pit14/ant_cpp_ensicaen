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

/***
 * function that will be called each day by each ant, they will just do their action for the day :
 * aging, eating, give birth, dying....
 */
void Queen::update(){
    setAge(getAge() + 1);
    //cout << nest->getFood() << endl;
    if (getAge() > QUEEN_LIFE_EXPECTANCY) {
        die();
    }else {
        if(eat()){
            if (age > 1) {
                give_birth();
            } else { // the first day she gave birth to a scout
                nest->add_ant(new Scout(nest));
                //nest->add_ant(new Worker(nest));
                give_birth();
            }
        }
    }
}

/***
 * the ant will eat his daily food dose needed to survive.
 * If there's not enough food in the nest, the ant will simply die.
 */
bool Queen::eat(){
    if(nest->getFood() > DAILY_FOOD_CONSUMPTION_QUEEN){
         nest->setFood(nest->getFood()- DAILY_FOOD_CONSUMPTION_QUEEN);
         return true;
    }else{
        this->die();
        return false;
    }
}

/***
 * we call the kill_ant function from the nest to delete the ant.
 */
void Queen::die(){
    nest->kill_ant(this);
}

/***
 * will randomly give irth to an ant by adding it to the list of ants of the nest
 */
void Queen::give_birth(){

    int random = rand() % 100 + 1;

    if(random <= 80) {
        nest->add_ant(new Worker(nest));
    } else if(random <= 95) {
        //nest->add_ant(new Soldier(nest));
    }else{
        nest->add_ant(new Scout(nest));
    }

}

