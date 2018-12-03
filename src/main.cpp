#include <iostream>
#include <string>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "Map/Grid.h"

using namespace std;



int main() {
/*
    //std::cout << "ddd" << std::endl;
    srand(time(NULL));
    Grid* g = new Grid();
    g->Initialize();

    g->array[0][9].food = 5;
    g->array[3][3].food = 9;
   // printf(g);
    g->create_original_colony();
    g->generate();
    return 0;*/


    // création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // on fait tourner le programme tant que la fenêtre n'a pas été fermée
    while (window.isOpen())
    {
        // on traite tous les évènements de la fenêtre qui ont été générés depuis la dernière itération de la boucle
        sf::Event event;
        while (window.pollEvent(event))
        {
            // fermeture de la fenêtre lorsque l'utilisateur le souhaite
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // effacement de la fenêtre en noir
        window.clear(sf::Color::Black);

        // c'est ici qu'on dessine tout
        // window.draw(...);

        // fin de la frame courante, affichage de tout ce qu'on a dessiné
        window.display();
    }

    return 0;
}


