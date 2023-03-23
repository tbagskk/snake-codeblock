#include "Snake.h"

int main()
{

    int vitesse = 200; // changer la valeur pour changer la vitesse
    char griid = 'y'; // mettre y pour afficher la grille ou n pour ne pas l'afficher

    sf::RenderWindow window(sf::VideoMode(WIDTH, 580), "Snake Alzubair ABDULRAHMAN");
    window.setPosition(sf::Vector2i(10, 50));
    Grid grid(GRID_WIDTH, GRID_HEIGHT, GRID_SIZE);
    Snake snake(0, 0, GRID_SIZE);
    //if (snake.parsing(3, vitesse) == 0) fonction pour le parsing si on utilise av et ac
       // return (0);
    snake.init(vitesse);
    snake.food();
    snake.speed_draw(window);
    char buffer[16];
    while (window.isOpen())
    {
        snake.travel(window);
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    snake.movement(event, window);
                    break;
                default:
                    break;
            }
        }
        snake.check(window);
        window.clear();
        if (griid == 'y')
            grid.draw(window);
        snake.draw(window);
        window.display();
        window.setVerticalSyncEnabled(false);
    }
    return 0;
}
