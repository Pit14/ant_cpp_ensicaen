//
// Created by Jerome on 28/11/2018.
//

#ifndef C_GRID_H
#define C_GRID_H

#include "Cell.h"

#define HEIGHT 10
#define WIDTH  10

class Grid {

public:
    Grid();
    void Initialize();
    Cell **array;
};


#endif //C_GRID_H
