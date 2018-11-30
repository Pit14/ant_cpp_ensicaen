//
// Created by Jerome on 28/11/2018.
//

#include <cmath>
#include <iostream>
#include "Grid.h"
#include "Cell.h"



Grid::Grid() {
    rock_value = round(HEIGHT*WIDTH*0.3);
}

bool Grid::isOutOfLimit( int x, int y) {
    if (x > WIDTH  || x < 0)
        return true;
    if (y > HEIGHT || y < 0)
        return true;
    return false;
}
bool Grid::noNeighbour( int x, int y) {

    if (!isOutOfLimit(x-1,y)) {
        if (array[x - 1][y].state != FREE)
            return false;
    }
    if(!isOutOfLimit(x+1,y)) {
        if (array[x + 1][y].state != FREE)
            return false;
    }
    if(!isOutOfLimit(x,y+1)) {
        if (array[x][y + 1].state != FREE)
            return false;
    }
    if(!isOutOfLimit(x,y-1)) {
        if (array[x][y - 1].state != FREE)
            return false;
    }
    return true;
}
bool Grid::isFree(int x, int y) {

    if (array[x][y].state == FREE)
        return true;
    return false;
}
void Grid::create_rock(double number_of_rock, int size_rock) {
    int cmptr;

    int x,y;

    for( cmptr = 0; cmptr < number_of_rock; cmptr++ ) {

        x = rand() % WIDTH;
        y = rand() % HEIGHT;

        if (isFree(x,y)){
            if (noNeighbour(x,y)) {

            }
        }
    }
}
void Grid::generate_rock() {

    create_rock(round(rock_value*0.5), 1);
    create_rock(round(rock_value*0.3), 2);
    create_rock(round(rock_value*0.1), 3);
    create_rock(round(rock_value*0.05), 4);
    create_rock(round(rock_value*0.04), 5);
    create_rock(round(rock_value*0.01), 6);

}
void Grid::Initialize() {


    array = new Cell* [HEIGHT];

    for (int cmptr(0); cmptr < HEIGHT; cmptr++) {
        array[cmptr] = new Cell[WIDTH];
        for (int cmptr2(0); cmptr2 < WIDTH; cmptr2++){
            Coord* temp_coord = new Coord(HEIGHT,WIDTH);

            setValue(array[cmptr][cmptr2], temp_coord,0,0,0,FREE);
        }
    }



}