//
// Created by edgar on 29/11/2018.
//

#ifndef C_DEFINE_H
#define C_DEFINE_H


#define HEIGHT 20
#define WIDTH  20

typedef enum {
    FREE, COLONY, BLOCKED, GHOST_ROCK
} state_cell;

typedef enum {
    NONE, LEFT, RIGHT, BOTTOM, TOP
} previous_pos;



#endif //C_DEFINE_H
