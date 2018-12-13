//
// Created by edgar on 29/11/2018.
//

#ifndef C_DEFINE_H
#define C_DEFINE_H


#define HEIGHT 211//211
#define WIDTH  201//201
#define WIND_WIDTH 800
#define WIND_HEIGHT 600
#define FOOD_1_case 10
#define BIG_FOOD 2000
#define LIFE_EXPECTANCY 365
#define EXECUTION_DELAY 10
#define QUEEN_LIFE_EXPECTANCY 365*10
#define INITIAL_FOOD_ON_NEST 200
#define DAILY_FOOD_CONSUMPTION_ANT 0.001
#define DAILY_FOOD_CONSUMPTION_QUEEN 0.01
#define WORKER_MINOR_DAY 15
#define SCOUT_MINOR_DAY 2

typedef enum {
    FREE, COLONY, BLOCKED, GHOST_ROCK, FOOD, GHOST_FOOD
} state_cell;

typedef enum {
    NONE, LEFT, RIGHT, BOTTOM, TOP
} previous_pos;



#endif //C_DEFINE_H
