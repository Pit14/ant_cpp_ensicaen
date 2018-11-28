//
// Created by edgar on 28/11/2018.
//
using namespace std;

#include "Soldier.h"
#include "BadAnt.h"

void Soldier::kill(BadAnt b) {
    b.die();
}
