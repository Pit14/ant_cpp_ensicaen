#include <iostream>
#include <string>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "Map/Grid.h"


using namespace std;

int main(){

    srand(time(NULL));
    Grid* g = new Grid();
    g->Initialize();

  /*  g->array[0][9].food = 5;
    g->array[3][3].food = 9;*/
    // printf(g);
    g->create_original_colony();
    g->generate();


}

