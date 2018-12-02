//
// Created by Jerome on 28/11/2018.
//

#include <cmath>
#include <iostream>
#include "Grid.h"
#include "Cell.h"



Grid::Grid() {
    rock_value = round(HEIGHT*WIDTH*0.3);
    food_number = round(HEIGHT*WIDTH*0.02);
}

void Grid::print_grid(){

    for(int y(0);y<HEIGHT;y++){
        for(int x(0);x<WIDTH;x++){
            if(array[x][y].state == BLOCKED)
                cout << 1;
            else if(array[x][y].state == FOOD)
                cout << 2;
            else if(array[x][y].state == COLONY)
                cout << 3;
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

bool Grid::recursive(int x, int y, int size_food, previous_pos old,int food_value ) {

    bool isOk = false;
    if (isFree(x,y)){


            array[x][y].state = GHOST_FOOD;
            if (size_food == 1) {
                //cout << x << " " << y << "food" << endl;
                array[x][y].state = FOOD;
                array[x][y].food = food_value;
                return true;
            }
            if (old != LEFT )
                isOk = recursive(x-1,y,size_food-1,RIGHT,2000);
            if (old != TOP && !isOk )
                isOk = recursive(x,y-1,size_food-1,BOTTOM,2000);
            if (old != RIGHT && !isOk)
                isOk = recursive(x+1,y,size_food-1,LEFT,2000);
            if (old != BOTTOM && !isOk)
                isOk = recursive(x,y+1,size_food-1,TOP,2000);

            if (isOk) {
                array[x][y].state = FOOD;
                //cout << x << " " << y << "food" << endl;
                return true;
            }
            array[x][y].state = FREE;

    }

    return false;
}
bool Grid::recursive(int x, int y, int size_rock, previous_pos old ) {

    bool isOk = false;
    if (isFree(x,y)){
        if (noNeighbour(x,y)) {

            array[x][y].state = GHOST_ROCK;
            if (size_rock == 1) {
                //cout << x << " " << y << "blocked" << endl;
                array[x][y].state = BLOCKED;
                return true;
            }
            if (old != LEFT )
                isOk = recursive(x-1,y,size_rock-1,RIGHT);
            if (old != TOP && !isOk )
                isOk = recursive(x,y-1,size_rock-1,BOTTOM);
            if (old != RIGHT && !isOk)
                isOk = recursive(x+1,y,size_rock-1,LEFT);
            if (old != BOTTOM && !isOk)
                isOk = recursive(x,y+1,size_rock-1,TOP);

            if (isOk) {
                array[x][y].state = BLOCKED;
                //cout << x << " " << y << "blocked" << endl;
                return true;
            }
            array[x][y].state = FREE;
        }
    }

    return false;
}


void Grid::create_rock(double number_of_rock, int size_rock) {
    int cmptr;

    int x,y;

    for( cmptr = 0; cmptr < number_of_rock; cmptr++ ) {

        x = rand() % WIDTH;
        y = rand() % HEIGHT;

        if (!recursive(x,y,size_rock, NONE))
           cmptr--;

    }
}

void Grid::create_food(double number_of_food, int size_food, int food_value) {
    int cmptr;

    int x,y;

    for( cmptr = 0; cmptr < number_of_food; cmptr++ ) {
        cout << 1 << endl;
        x = rand() % WIDTH;
        y = rand() % HEIGHT;

        if (!recursive(x,y,size_food, NONE, food_value))
            cmptr--;

    }
}
void Grid::generate() {


    create_rock(round((rock_value*0.01)/6), 6);
    create_rock(round((rock_value*0.04)/5), 5);
    create_rock(round((rock_value*0.05)/4), 4);
    create_rock(round((rock_value*0.1)/3), 3);
    create_rock(round((rock_value*0.3)/2), 2);
    create_rock(round(rock_value*0.5), 1);

    create_food(food_number,1, FOOD_1_case);
    create_food(2,5,BIG_FOOD);


    print_grid();



}
void Grid::create_original_colony() {

    int x = (int) round(WIDTH/2);
    int y = (int) round(HEIGHT/2);
    array[x][y].state = COLONY;
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