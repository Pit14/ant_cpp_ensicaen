//
// Created by edgar on 29/11/2018.
//

#ifndef C_DEFINE_H
#define C_DEFINE_H


#define HEIGHT 211
#define WIDTH  201
#define FOOD_1_case 10
#define BIG_FOOD 2000

typedef enum {
    FREE, COLONY, BLOCKED, GHOST_ROCK, FOOD, GHOST_FOOD
} state_cell;

typedef enum {
    NONE, LEFT, RIGHT, BOTTOM, TOP
} previous_pos;



#endif //C_DEFINE_H
