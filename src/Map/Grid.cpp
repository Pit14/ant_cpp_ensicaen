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

void Grid::print_grid(){

    for(int y(0);y<HEIGHT;y++){
        for(int x(0);x<WIDTH;x++){
            if(array[x][y].state == BLOCKED)
                cout << 1;
            else
                cout << 0;
        }
        cout << endl;
    }
}

bool Grid::isOutOfLimit( int x, int y) {
    if (x >= WIDTH  || x < 0)
        return true;
    if (y >= HEIGHT || y < 0)
        return true;
    //cout << x << " "<< y << " is ok"<< endl;
    return false;
}
bool Grid::noNeighbour( int x, int y) {

    if (!isOutOfLimit(x-1,y)) {
        if (array[x - 1][y].state == BLOCKED)
            return false;
    }
    if(!isOutOfLimit(x+1,y)) {
        if (array[x + 1][y].state == BLOCKED)
            return false;
    }
    if(!isOutOfLimit(x,y+1)) {
        if (array[x][y + 1].state == BLOCKED)
            return false;
    }
    if(!isOutOfLimit(x,y-1)) {
        if (array[x][y - 1].state == BLOCKED)
            return false;
    }
  //  cout <<  "no voisin" << endl;
    return true;
}
bool Grid::isFree(int x, int y) {
    if (!isOutOfLimit(x,y)) {
        if (array[x][y].state == FREE) {
        //    cout << "free" << endl;

            return true;
        }
    }
    return false;
}

bool Grid::recursive_rock(int x, int y, int size_rock, previous_pos old ) {

    bool isOk = false;
    if (isFree(x,y)){
        //if (noNeighbour(x,y)) {

            array[x][y].state = GHOST_ROCK;
            if (size_rock == 1) {
                cout << x << " " << y << "blocked" << endl;
                array[x][y].state = BLOCKED;
                return true;
            }
            if (old != LEFT )
                isOk = recursive_rock(x-1,y,size_rock-1,RIGHT);
            if (old != TOP && !isOk )
                isOk = recursive_rock(x,y-1,size_rock-1,BOTTOM);
            if (old != RIGHT && !isOk)
                isOk = recursive_rock(x+1,y,size_rock-1,LEFT);
            if (old != BOTTOM && !isOk)
                isOk = recursive_rock(x,y+1,size_rock-1,TOP);

            if (isOk) {
                array[x][y].state = BLOCKED;
                cout << x << " " << y << "blocked" << endl;
                return true;
            }
            array[x][y].state = FREE;
        //}
    }

    return false;
}
void Grid::create_rock(double number_of_rock, int size_rock) {
    int cmptr;

    int x,y;

    for( cmptr = 0; cmptr < number_of_rock; cmptr++ ) {

        x = rand() % WIDTH;
        y = rand() % HEIGHT;

        if (!recursive_rock(x,y,size_rock, NONE))
           cmptr--;
        else
            print_grid();
    }
}
void Grid::generate_rock() {


    create_rock(round(rock_value*0.01), 6);
     create_rock(round(rock_value*0.04), 5);
     create_rock(round(rock_value*0.05), 4);
    create_rock(round(rock_value*0.1), 3);
    create_rock(round(rock_value*0.3), 2);
    create_rock(round(rock_value*0.5), 1);





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