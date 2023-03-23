#include "Snake.h"



Grid::Grid(int width, int height, int size) : m_width(width), m_height(height), m_size(size) {

    for (int i = 0; i < m_height; i++) {
        std::vector<sf::RectangleShape> row;
        for (int j = 0; j < m_width; j++) {
            sf::RectangleShape square(sf::Vector2f(m_size, m_size));
            square.setPosition(j * m_size, i * m_size);
            square.setFillColor(sf::Color::Black);
            square.setOutlineThickness(1);
            square.setOutlineColor(sf::Color::White);
            row.push_back(square);
        }
        m_grid.push_back(row);
    }
}

void Grid::draw(sf::RenderWindow& window) const {

    for (int i = 0; i < m_height; i++) {
        for (int j = 0; j < m_width; j++) {
            window.draw(m_grid[i][j]);
        }
    }
}
