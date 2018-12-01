#include <iostream>
#include <string>
#include <ctime>
#include "Map/Grid.h"
using namespace std;



int main() {

    //std::cout << "ddd" << std::endl;
    srand(time(NULL));
    Grid* g = new Grid();
    g->Initialize();

    g->array[0][9].food = 5;
    g->array[3][3].food = 9;
   // printf(g);
    g->generate_rock();
    return 0;
}


