#include <iostream>
#include <string>
#include "Map/Grid.h"

using namespace std;

void printf(Grid* g){

    for(int x(0);x<10;x++){
        for(int y(0);y<10;y++){
            cout << g->array[x][y].food;
        }
        cout << endl;
    }
}

int main() {

    //std::cout << "ddd" << std::endl;

    Grid* g = new Grid();
    g->Initialize();

    g->array[0][9].food = 5;
    g->array[3][3].food = 9;
    printf(g);
    g->generate_rock();
    return 0;
}


