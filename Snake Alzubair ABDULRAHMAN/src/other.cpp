#include "Snake.h"


//fonction pour initialiser les différentes valeurs

void Snake::init(int i)
{
    speed = i;
    win = 0;
    left = false;
    right = true;
    up = false;
    down = false;
}

//fonction pour changer la direction du serpent en fonction de la touche pressé

void Snake::movement(Event &event, sf::RenderWindow& window)
{
    if (event.key.code == sf::Keyboard::Left)
    {
        left = true;
        right = false;
        up = false;
        down = false;
    }
    else if (event.key.code == sf::Keyboard::Right)
    {
        left = false;
        right = true;
        up = false;
        down = false;
    }
    else if (event.key.code == sf::Keyboard::Up)
    {
        left = false;
        right = false;
        up = true;
        down = false;
    }
    else if (event.key.code == sf::Keyboard::Down)
    {
        left = false;
        right = false;
        up = false;
        down = true;
    }
}

//fonction pour vérifier les collisions avec les murs ou avec la queue du serpent

void Snake::check(sf::RenderWindow& window)
{
    int i = 2;
    if (tab[0].getPosition().x > 720 || tab[0].getPosition().x < 0)
        window.close();
    if (tab[0].getPosition().y > 480 || tab[0].getPosition().y < 0)
        window.close();
    while(i < tab.size())
    {
        if(tab[0].getPosition().x == tab[i].getPosition().x && tab[0].getPosition().y == tab[i].getPosition().y)
            window.close();
        i++;
    }
}

//fonction pour afficher le score

void Snake::score(sf::RenderWindow& window)
{

    font.loadFromFile("police/Roboto-Black.ttf");

    score_text.setFont(font);
    score_text.setString("SCORE :");
    score_text.setCharacterSize(30);
    score_text.setPosition(40,540);
    score_text.setFillColor(sf::Color::White);

    text.setFont(font);
    std::string s = std::to_string(win);
    text.setString(s);
    text.setCharacterSize(30);
    text.setPosition(170,540);
    text.setFillColor(sf::Color::Red);

    window.draw(score_text);
    window.draw(text);
}

//fonction pour afficher la vitesse du serpent choisi

void Snake::speed_draw(sf::RenderWindow& window)
{
    font.loadFromFile("police/Roboto-Black.ttf");

    speed_text.setFont(font);
    speed_text.setString("VITESSE :");
    speed_text.setCharacterSize(30);
    speed_text.setPosition(540,540);
    speed_text.setFillColor(sf::Color::White);

    speed_d.setFont(font);
    std::string s = std::to_string(speed);
    speed_d.setString(s);
    speed_d.setCharacterSize(30);
    speed_d.setPosition(690,540);
    speed_d.setFillColor(sf::Color::Red);

    window.draw(speed_d);
    window.draw(speed_text);

}

//fonction pour vérifier si les entrés sont viables si on utilise ac et av

int Snake::parsing(int ac, char **av)
{
    int i = 0;
    if (ac != 3)
    {
         printf("Erreur : entrez ./snake <<vitesse en m/s>> et <<y>> pour afficher la grille ou <<n>>\n");
         return (0);
    }
    while (av[1][i])
    {
        if (av[1][i] >= '0' && av[1][i] <= '9')
            i++;
        else
        {
            printf("Erreur : entrez ./snake <<vitesse en m/s>>\n");
            return (0);
        }
    }
    return (1);
}
