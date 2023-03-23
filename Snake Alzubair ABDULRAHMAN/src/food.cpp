#include "Snake.h"
//fonction qui permet de générer aleatoirement une position pour la nouriture du serpent

void Snake::food()
{
    int i = 0;
    int x = rand() % GRID_WIDTH;
    int y = rand() % GRID_HEIGHT;
    snake_food.setSize(sf::Vector2f(GRID_SIZE - 3, GRID_SIZE - 3));
    snake_food.setFillColor(sf::Color::Blue);
    snake_food.setPosition(x * 60, y * 60);
}

//fonction pour vérifier si le serpent à mangé la nourriture

void Snake::eating()
{
    if (tab[0].getPosition().x == snake_food.getPosition().x && tab[0].getPosition().y == snake_food.getPosition().y)
    {
        add_case();
        food();
    }
}
