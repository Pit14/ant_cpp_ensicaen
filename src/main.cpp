#include <iostream>
#include <string>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "Map/Grid.h"


using namespace std;


bool intersects(const sf::CircleShape& c1, const sf::CircleShape& c2){
    sf::FloatRect circ1 = c1.getGlobalBounds();
    sf::FloatRect circ2 = c2.getGlobalBounds();

    return circ1.intersects(circ2);
}

int main(){

    srand(time(NULL));
    Grid* g = new Grid();
    g->Initialize();

    g->array[0][9].food = 5;
    g->array[3][3].food = 9;
    // printf(g);
    g->create_original_colony();
    g->generate();

    sf::VideoMode videomode(400, 400);
    sf::RenderWindow window(videomode, "GAME");
    sf::CircleShape circle;
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(100, 100);
    circle.setRadius(20);
    sf::CircleShape circle2;
    circle2.setFillColor(sf::Color::Yellow);
    circle2.setPosition(200, 200);
    circle2.setRadius(20);
    sf::CircleShape circle3;
    circle3.setFillColor(sf::Color::Black);
    circle3.setPosition(300, 300);
    circle3.setRadius(50);


    while (window.isOpen()&&(!intersects(circle,circle3))&&(!intersects(circle2,circle3))){
        window.clear(sf::Color::Blue);
        window.draw(circle);
        window.draw(circle2);
        window.draw(circle3);

        window.display();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }






        if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Up)){
            circle.move(0, -0.5);


        }

        else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Down)){
            circle.move(0, 0.5);


        }

        else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Right)){
            circle.move(0.5, 0);



        }

        else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Left)){
            circle.move(-0.5, 0);





        }



        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            circle2.move(0, -0.5);


        }


        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            circle2.move(0, 0.5);


        }


        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            circle2.move(0.5, 0);


        }


        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            circle2.move(-0.5, 0);


        }







        if (intersects(circle, circle2)){
            circle2.move(0.5, 0);
        }
        if (intersects(circle2, circle)){
            circle.move(0.5, 0);

        }
        if (intersects(circle, circle3)){

            std::cout << "Red loses";
        }
        if (intersects(circle2, circle3)){

            std::cout << "Yellow loses";
        }
    }
}

