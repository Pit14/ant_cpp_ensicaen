//
// Created by edgar on 29/11/2018.
//

#ifndef C_DEFINE_H
#define C_DEFINE_H


#define HEIGHT 31//211
#define WIDTH  31//201
#define FOOD_1_case 10
#define BIG_FOOD 2000
#define LIFE_EXPECTANCY 365
#define QUEEN_LIFE_EXPECTANCY 365*10

typedef enum {
    FREE, COLONY, BLOCKED, GHOST_ROCK, FOOD, GHOST_FOOD
} state_cell;

typedef enum {
    NONE, LEFT, RIGHT, BOTTOM, TOP
} previous_pos;



#endif //C_DEFINE_H
