#ifndef PALETKA_H
#define PALETKA_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<string>

class Paletka// : public sf::RectangleShape
{
public:
    Paletka(std::string direction);
    void rysowaniep(sf::RenderWindow &w) ;
    void pozycja(float x, float y) ;
    float nadajpozycjex() ;
    float nadajpozycjey();
    void ruch(float x, float y, float delta) ;
    sf::FloatRect bound() ;

private:
    sf::Sprite paletka;
    sf::Texture tex;
};

#endif // PALETKA_H
