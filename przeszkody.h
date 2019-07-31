#ifndef PRZESZKODY_H
#define PRZESZKODY_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<string>

class przeszkody
{
public:
    przeszkody();
    void rysowaniep(sf::RenderWindow &w);
    void obrot(float g, float delta);
    sf::FloatRect boundprzeszkody();
    bool znikanieprzeszkody(sf::FloatRect obiekt);
private:
    sf::RectangleShape przeszkoda;
};

#endif // PRZESZKODY_H
