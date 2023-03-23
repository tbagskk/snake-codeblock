#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;
using namespace sf;

const int WIDTH = 780;
const int HEIGHT = 540;
const int GRID_WIDTH = 13;
const int GRID_HEIGHT = 9;
const int GRID_SIZE = 60;

class Grid {
public:
    Grid(int width, int height, int size);
    void draw(sf::RenderWindow& window) const;

private:
    int m_width, m_height, m_size;
    std::vector<std::vector<sf::RectangleShape>> m_grid;
};

class Snake {
public:
    Snake(float x, float y, int size){
        add_case();
        add_case();
        time = 0.0f;
    };
    void draw(sf::RenderWindow& window);
    void food();
    void add_case();
    void eating();
    void travel(sf::RenderWindow& window);
    void init(int speed);
    void score(sf::RenderWindow& window);
    void check(sf::RenderWindow& window);
    void movement(Event &event, sf::RenderWindow& window);
    int parsing(int ac, char **av);
    void speed_draw(sf::RenderWindow& window);
    std::vector<sf::RectangleShape> tab;

private:

    sf::RectangleShape snake_food;
    sf::Clock mClock;
    sf::Font font;
    sf::Text text;
    sf::Text speed_d;
    sf::Text score_text;
    sf::Text speed_text;
    int m_size, time, real_time, speed, x, y, win;
    bool left, right, up, down;
};


#endif // SNAKE_H
