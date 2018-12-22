//
// Created by Jerome on 28/11/2018.
//

#include <cmath>
#include <iostream>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics.hpp>
#include <zconf.h>
#include "../../include/Map/Grid.h"
#include "../../include/Map/Cell.h"
#include <chrono>
#include <typeinfo>
#include <thread>
#include <fstream>
#include "../../include/Ants/Queen.h"
#include "../../include/Ants/Nest.h"
using namespace WIND;
using namespace DATA;
using namespace FOODS;

Grid::Grid()
{

    rock_value = round(HEIGHT*WIDTH*0.3);
    food_number = round(HEIGHT*WIDTH*FOOD_PERCENTAGE );


    sf::Sprite sprites;
    fourmis.loadFromFile("../Ressources/pic/scout.png");
    bouffe.loadFromFile("../Ressources/pic/food.png");
    gazon.loadFromFile("../Ressources/pic/pelouse.jpg");
    colony.loadFromFile("../Ressources/pic/colony.jpg");
    rock.loadFromFile("../Ressources/pic/rock.png");
    fog.loadFromFile("../Ressources/pic/black.jpg");
    worker.loadFromFile("../Ressources/pic/worker.png");
    soldier.loadFromFile("../Ressources/pic/soldier.png");
    badAnt.loadFromFile("../Ressources/pic/badAnt.png");
    ping = 700;
}

/***
 * load all the element of the map, rock, foods and fog...
 * it checks all the state of the cell and apply a sprite of 32*32 on the x*32 pixel and y*32 pixel
 * and then draw it on the window
 * @param window
 */
void Grid::loadSprite(sf::RenderWindow &window) {


    for (int y(0); y < HEIGHT; y++) {
        for (int x(0); x < WIDTH; x++) {

            if (array[x][y].getHide() == true) {
                sprites.setTexture(fog);
            } else {

                if (array[x][y].getState() == BLOCKED)
                    sprites.setTexture(rock);
                else if (array[x][y].getState() == FOOD)
                    sprites.setTexture(bouffe);
                else if (array[x][y].getState() == COLONY)
                    sprites.setTexture(colony);
                else
                    sprites.setTexture(gazon);
            }

            sprites.setTextureRect(sf::IntRect(0, 0, 32, 32));
            sprites.setPosition(32 * x, 32 * y);
            window.draw(sprites);
        }
    }
}
/***
 * load all the differents sprite for the ants
 * it checks all the list of all ants and then use a dynamic cast to know what is the type of the ant
 * and then draw it on the window
 * @param window
 */
int Grid::loadAnts(sf::RenderWindow &window, list<Ant*> ants) {

    int cmptr = 0;
    Coord *temp = new Coord(0,0);
    for(std::list<Ant*>::iterator it = ants.begin(); it!=ants.end(); ++it)
    {

        cmptr ++ ;
        *temp = (*it)->getCoord();
        if((dynamic_cast<Scout*>(*it) != nullptr))
        {
            sprites.setTexture(fourmis);
        }

        if((dynamic_cast<Worker*>(*it) != nullptr))
        {
            sprites.setTexture(worker);
        }

        if((dynamic_cast<Soldier*>(*it) != nullptr))
        {
            sprites.setTexture(soldier);
        }

        if((dynamic_cast<BadAnt*>(*it) != nullptr))
        {
            sprites.setTexture(badAnt);
        }
            sprites.setTextureRect(sf::IntRect(0, 0, 32, 32));
            sprites.setPosition(32 * temp->getX(), 32 * temp->getY());
            window.draw(sprites);



    }

    return cmptr;
}

/***
 * show on the window a string containing main statistic of the simulation
 * @param window
 * @param cmptr_ant
 * @param text
 */
void Grid::show_stat(sf::RenderWindow &window, int cmptr_ant, sf::Text text) {
    text.setString("Day : "+to_string(day)+" Ant : "+to_string(cmptr_ant)+" Food : "+to_string(nest->getFood())+" Speed : "+to_string(ping)+"ms");
    window.draw(text);
}

/***
 * write in a file the statistic of the simulation, when launching gnuplot, it will open that file
 * @param cmptr_ant
 * @param ofs
 */
void Grid::write_gnuplot( int cmptr_ant, std::ofstream &ofs) {
    ofs << to_string(day) << " " << to_string(cmptr_ant) << " " << to_string(nest->getFood()) << "\n";

}

/***
 * Main function which will call all the update and refresh function
 * it also use listener on the windows to know the position of mouse and move the screen in case of click by user
 */
void Grid::print_grid(){




    sf::VideoMode desktop = sf::VideoMode().getDesktopMode();
    sf::RenderWindow window(desktop, "SFML works!");
    sf::Clock clock;
    sf::Time elapsed1;
    window.setFramerateLimit(30);

    sf::Vector2f oldPos;
    bool moving = false;
    int cmptr_ant = 0;
    std::ofstream ofs;
    ofs.open("../etc/evolution.txt", std::ofstream::trunc);

    float zoom = 1;

    list<Ant*> ants;


    sf::Font font;
    font.loadFromFile("../Ressources/arial.ttf");
    sf::Text text;


    text.setFont(font);


    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text.setPosition((WIDTH*32/2)-WIND_WIDTH+200,(HEIGHT*32/2)-WIND_HEIGHT-120);


    sf::View view = window.getDefaultView();
    view.setCenter((HEIGHT*32)/2,(WIDTH*32)/2);
    zoom = 2.f;
    view.zoom(zoom);
    window.setView(view);

    window.display();


    while(window.isOpen()) {


        window.clear();


        elapsed1 = clock.getElapsedTime();

        loadSprite(window);
        cmptr_ant = loadAnts(window, ants);
        show_stat(window,cmptr_ant,text);
        window.draw(text);
        if (elapsed1.asMilliseconds()> ping) {
            day++;
            if(nest->update_nest() == true) {
                window.close();
                cout << "FIN DE LA SIMULATION " << endl;
            }
            ants = nest->getAnts();
            write_gnuplot(cmptr_ant,ofs);


            clock.restart();
        }



        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:

                    if (event.mouseButton.button == 0) {
                        moving = true;
                        oldPos = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                    }
                    break;
                case  sf::Event::MouseButtonReleased:

                    if (event.mouseButton.button == 0) {
                        moving = false;
                    }
                    break;


                case sf::Event::KeyPressed:

                    if (event.key.code == sf::Keyboard::Right)
                        if( ping > 11 ) {
                            ping = ping - EXECUTION_DELAY;
                            break;
                        }

                    if(event.key.code == sf::Keyboard::Left)
                        if (ping < 1500)
                            ping = ping + EXECUTION_DELAY;
                    break;

                case sf::Event::MouseMoved:
                {

                    if (!moving)
                        break;

                    const sf::Vector2f newPos = window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));

                    const sf::Vector2f deltaPos = oldPos - newPos;
                    sf::Vector2f deltaPos2 = oldPos - newPos;


                    deltaPos2.x = deltaPos2.x-WIND_WIDTH+30;
                    deltaPos2.y = deltaPos2.y-WIND_HEIGHT +20;
                    view.setCenter(view.getCenter() + deltaPos);
                    text.setPosition(view.getCenter()+deltaPos2);
                    window.setView(view);


                    oldPos = window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
                    break;
                }
                case sf::Event::MouseWheelScrolled:

                    if (moving)
                        break;


                    if (event.mouseWheelScroll.delta <= -1)
                        zoom = std::min(10.f, zoom + .1f);
                    else if (event.mouseWheelScroll.delta >= 1)
                        zoom = std::max(.5f, zoom - .1f);

                    // Update our view
                    view.setSize(window.getDefaultView().getSize()); // Reset the size
                    view.zoom(zoom); // Apply the zoom level (this transforms the view)

                    window.setView(view);
                    break;
            }
        }



        window.display();

    }

    ofs.close();

    system("start \"D:\\Program Files\\gnuplot\\bin\\gnuplot.exe\" ../etc/command.gp ");


}

/***
 * check if the coord (x,y) of out of the limit of the array
 * @param x
 * @param y
 */
bool Grid::isOutOfLimit( int x, int y) {
    if (x >= WIDTH  || x < 0)
        return true;
    if (y >= HEIGHT || y < 0)
        return true;

    return false;
}

/***
 * check if there is a block cell in the neighbour of the current cell
 * @param x
 * @param y
 */
bool Grid::noNeighbour( int x, int y) {

    if (!isOutOfLimit(x-1,y)) {
        if (array[x - 1][y].getState() == BLOCKED)
            return false;
    }
    if(!isOutOfLimit(x+1,y)) {
        if (array[x + 1][y].getState() == BLOCKED)
            return false;
    }
    if(!isOutOfLimit(x,y+1)) {
        if (array[x][y + 1].getState() == BLOCKED)
            return false;
    }
    if(!isOutOfLimit(x,y-1)) {
        if (array[x][y - 1].getState() == BLOCKED)
            return false;
    }

    return true;
}

/***
 * check if  the case we want to check is free or if there is a FOOD or BLOCK yet
 * @param x
 * @param y
 */
bool Grid::isFree(int x, int y) {
    if (!isOutOfLimit(x,y)) {
        if (array[x][y].getState() == FREE) {
            return true;
        }
    }
    return false;
}

/***
 * this function will generate the food in simple block or several one using the principle of back-tracking
 * @param x
 * @param y
 * @param size_food
 * @param old
 * @param food_value
 */
bool Grid::recursive(int x, int y, int size_food, previous_pos old,int food_value ) {

    bool isOk = false;
    if (isFree(x,y)){


            array[x][y].setState(GHOST_FOOD);
            if (size_food == 1) {

                array[x][y].setState(FOOD);
                array[x][y].setFood(food_value);
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
                array[x][y].setState(FOOD);

                return true;
            }
            array[x][y].setState(FREE);

    }

    return false;
}

/***
 * this function will generate the rock in simple block or several one using the principle of back-tracking
 * @param x
 * @param y
 * @param size_rock
 * @param old
 */
bool Grid::recursive(int x, int y, int size_rock, previous_pos old ) {

    bool isOk = false;
    if (isFree(x,y)){
        if (noNeighbour(x,y)) {

            array[x][y].setState(GHOST_ROCK);
            if (size_rock == 1) {

                array[x][y].setState(BLOCKED);
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
                array[x][y].setState(BLOCKED);

                return true;
            }
            array[x][y].setState(FREE);
        }
    }

    return false;
}

/***
 * this function will choose a random position to call after the function which will generate rock
 * @param number_of_rock
 * @param size_rock
 */
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
/***
 * this function will choose a random position to call after the function which will generate food
 * @param number_of_food
 * @param size_food
 * @param food_value
 */
void Grid::create_food(double number_of_food, int size_food, int food_value) {
    int cmptr;

    int x,y;

    for( cmptr = 0; cmptr < number_of_food; cmptr++ ) {

        x = rand() % WIDTH;
        y = rand() % HEIGHT;

        if (!recursive(x,y,size_food, NONE, food_value))
            cmptr--;

    }
}
/***
 * this function will call several time the functions that will generate elements of the map
 */
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

/***
 * initialize the colony at the center of the map
 */
void Grid::create_original_colony() {

    int x = (int) round(WIDTH/2);
    int y = (int) round(HEIGHT/2);
    array[x][y].setState(COLONY);
    array[x][y].setVisible();
}

/***
 * initialize the array containing the cells
 * and create the nest
 */
void Grid::Initialize() {


    array = new Cell* [HEIGHT];

    for (int cmptr(0); cmptr < HEIGHT; cmptr++) {
        array[cmptr] = new Cell[WIDTH];
        for (int cmptr2(0); cmptr2 < WIDTH; cmptr2++){
            Coord* temp_coord = new Coord(HEIGHT,WIDTH);

            array[cmptr][cmptr2].setValue( temp_coord,0,0,0);
            array[cmptr][cmptr2].setState(FREE);
        }
    }

    //we create the nest

    nest = new Nest(array);


}