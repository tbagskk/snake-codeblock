#include "Snake.h"

//ajoute a tab[] un rectangle si le serpent manges la nouriture

void Snake::add_case()
{
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE));
    rect.setFillColor(sf::Color::Red);
    if (tab.empty())
        rect.setFillColor(sf::Color::White);
    else if (tab.size() == 1)
        rect.setPosition(tab[0].getPosition().x, tab[0].getPosition().y);
    else
        rect.setPosition(tab[1].getPosition().x, tab[1].getPosition().y);
    win++;
   tab.push_back(rect);
}

//fait avancer le serpent chaque xTemps dans la direction choisi

void Snake::travel(sf::RenderWindow& window)
{
    int i = tab.size() - 1;
    if (time < speed)
        time += mClock.restart().asMilliseconds();
    else
    {
        time = 0.0f;
        while(i > 0)
        {
            tab[i].setPosition(sf::Vector2f(tab[i-1].getPosition().x, tab[i-1].getPosition().y));
            i--;
        }
        if (left == true)
            tab[0].move(-60, 0);
        else if (right == true)
            tab[0].move(60, 0);
        else if (up == true)
            tab[0].move(0, -60);
        else if (down == true)
            tab[0].move(0, 60);

    }
    eating();
}

// fonction qui dessine le serpent a l'ecran

void Snake::draw(sf::RenderWindow& window)
{
    int i = 0;
    window.draw(snake_food);
    while (i < tab.size())
    {
        window.draw(tab[i]);
        i++;
     }
    score(window);
    speed_draw(window);
}

