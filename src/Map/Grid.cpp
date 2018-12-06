//
// Created by Jerome on 28/11/2018.
//

#include <cmath>
#include <iostream>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics.hpp>
#include <zconf.h>
#include "Grid.h"
#include "Cell.h"
#include "../Ants/Queen.h"
#include "../Ants/Nest.h"


Grid::Grid()
{

    rock_value = round(HEIGHT*WIDTH*0.3);
    food_number = round(HEIGHT*WIDTH*0.0002);



    sf::Sprite sprites;
    fourmis.loadFromFile("../src/pic/ant.jpg");
    bouffe.loadFromFile("../src/pic/food.jpg");
    gazon.loadFromFile("../src/pic/pelouse.jpg");
    colony.loadFromFile("../src/pic/colony.jpg");
    rock.loadFromFile("../src/pic/rock.png");
}


void Grid::loadSprite(sf::RenderWindow &window) {


    for (int y(0); y < HEIGHT; y++) {
        for (int x(0); x < WIDTH; x++) {



            if (array[x][y].state == BLOCKED)
                sprites.setTexture(rock);
            else if (array[x][y].state == FOOD)
                sprites.setTexture(bouffe);
            else if (array[x][y].state == COLONY)
                sprites.setTexture(colony);
            else
                sprites.setTexture(gazon);

            sprites.setTextureRect(sf::IntRect(0, 0, 100, 100));
            sprites.setPosition(32 * x + 1, 32 * y + 1);
            window.draw(sprites);
        }
    }
}
void Grid::print_grid(){



    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    window.setFramerateLimit(30);
    //window.setFramerateLimit(100);
    sf::Vector2f oldPos;
    bool moving = false;

    float zoom = 1;

    // Retrieve the window's default view
    sf::View view = window.getDefaultView();


    while(window.isOpen()) {
        window.clear();
        nest->update_nest();
        loadSprite(window);


        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    // Mouse button is pressed, get the position and set moving as active
                    if (event.mouseButton.button == 0) {
                        moving = true;
                        oldPos = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                    }
                    break;
                case  sf::Event::MouseButtonReleased:
                    // Mouse button is released, no longer move
                    if (event.mouseButton.button == 0) {
                        moving = false;
                    }
                    break;
                case sf::Event::MouseMoved:
                {
                    // Ignore mouse movement unless a button is pressed (see above)
                    if (!moving)
                        break;
                    // Determine the new position in world coordinates
                    const sf::Vector2f newPos = window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
                    // Determine how the cursor has moved
                    // Swap these to invert the movement direction
                    const sf::Vector2f deltaPos = oldPos - newPos;

                    // Move our view accordingly and update the window
                    view.setCenter(view.getCenter() + deltaPos);
                    window.setView(view);

                    // Save the new position as the old one
                    // We're recalculating this, since we've changed the view
                    oldPos = window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
                    break;
                }
                case sf::Event::MouseWheelScrolled:
                    // Ignore the mouse wheel unless we're not moving
                    if (moving)
                        break;

                    // Determine the scroll direction and adjust the zoom level
                    // Again, you can swap these to invert the direction
                    if (event.mouseWheelScroll.delta <= -1)
                        zoom = std::min(2.f, zoom + .1f);
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
    //    cout << 1 << endl;
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

    //we create the nest
    nest = new Nest();




}