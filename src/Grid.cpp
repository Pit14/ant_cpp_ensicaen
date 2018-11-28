//
// Created by Jerome on 28/11/2018.
//

#include "Grid.h"
#include "Cell.h"

Grid::Grid(){};


void Grid::Initialize() {

    Cell **array;
    array = new Cell* [HEIGHT];

    for (int cmptr(0); cmptr < HEIGHT; cmptr++) {
        array[cmptr] = new Cell[WIDTH];
        for (int cmptr2(0); cmptr2 < WIDTH; cmptr2++){
            array[cmptr][cmptr2].setValue(new Coord(cmptr,cmptr2),0,0,0,FREE);
        }
    }



}