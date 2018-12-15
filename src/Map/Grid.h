//
// Created by Jerome on 28/11/2018.
//

#ifndef C_GRID_H
#define C_GRID_H

#include "Cell.h"
#include "../define.h"
#include "../Ants/Nest.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics.hpp>


class Grid {


public:
    Grid();
    void Initialize();
    void generate();
    void create_original_colony();
    void create_rock(double number_of_rock, int size_rock);
    void create_food(double number_of_food, int size_food, int food_value);
    bool isFree(int x, int y);
    bool noNeighbour (int x, int y);
    static bool isOutOfLimit(int x, int y);
    bool recursive(int x, int y, int size_rock, previous_pos old );
    bool recursive(int x, int y,int size_rock, previous_pos old , int food_value);
    void print_grid ();
    void loadSprite(sf::RenderWindow &window);
    int loadAnts(sf::RenderWindow &window, list<Ant*> ants);
    void show_stat(sf::RenderWindow &window, int cmptr_ant, sf::Text text);
    void write_gnuplot( int cmptr_ant, std::ofstream &ofs);
    Cell **array;
    double rock_value;
    double food_number;

    sf::Sprite sprites;
    sf::Texture fourmis;
    sf::Texture bouffe;
    sf::Texture gazon;
    sf::Texture colony;
    sf::Texture rock;
    sf::Texture fog;
    sf::Texture worker;
    sf::Texture soldier;

private:
    Nest *nest;
    int day;
    int ping;

};


#endif //C_GRID_H
