//
// Created by Jerome on 28/11/2018.
//

#ifndef C_GRID_H
#define C_GRID_H

#include "Cell.h"
#include "../define.h"


class Grid {

public:
    Grid();
    void Initialize();
    void generate_rock();
    void create_rock(double number_of_rock, int size_rock);
    bool isFree(int x, int y);
    bool noNeighbour (int x, int y);
    bool isOutOfLimit(int x, int y);
    Cell **array;
    double rock_value;
};


#endif //C_GRID_H
