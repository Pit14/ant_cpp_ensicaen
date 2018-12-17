//
// Created by edgar on 29/11/2018.
//

#ifndef C_DEFINE_H
#define C_DEFINE_H

namespace  colony {
    class BadAnt;
    class Ant;
    class Queen;
    class Scout;
    class Soldier;
    class Worker;

}
namespace  DATA {
    const int LIFE_EXPECTANCY = 365;
    const int  EXECUTION_DELAY = 10;
    const int QUEEN_LIFE_EXPECTANCY = 365*10;
    const int  WORKER_MINOR_DAY = 15;
    const int SCOUT_MINOR_DAY = 2;
}
namespace WIND {
    const int HEIGHT = 211;
    const int WIDTH = 201;
    const int WIND_WIDTH = 800;
    const int WIND_HEIGHT = 600;
}

namespace FOODS {
const int FOOD_1_case = 10;
const int BIG_FOOD = 2000;
const int INITIAL_FOOD_ON_NEST = 2;
const float DAILY_FOOD_CONSUMPTION_ANT = 0.001;
const float DAILY_FOOD_CONSUMPTION_QUEEN = 0.01;
const float FOOD_PERCENTAGE =0.03;//0.0002
}

typedef enum {
    FREE, COLONY, BLOCKED, GHOST_ROCK, FOOD, GHOST_FOOD
} state_cell;

typedef enum {
    NONE, LEFT, RIGHT, BOTTOM, TOP
} previous_pos;



#endif //C_DEFINE_H
