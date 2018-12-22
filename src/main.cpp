#include <iostream>
#include <string>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "../include/Map/Grid.h"


using namespace std;

int main(){

    srand(time(NULL));
    Grid* g = new Grid();
    g->Initialize();


    g->create_original_colony();
    g->generate();


}

