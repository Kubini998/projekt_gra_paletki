#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
class menu :public sf::Drawable
{
public:
    menu(std::string direction);
    ~menu();
    void draw(sf::RenderTarget& target, sf::RenderStates state) const;
    void set_position(float iks, float igrek);
    void set_texture(std::string tex);
    sf::Sprite Zwroc_bohatera();


private:
    sf::Sprite Bohater;
    std::string NazwaTekstury_;
    sf::Texture TexturaBohatera_;
    sf::Vector2f RozmiarBohatera_;
    int Szerokosc_;
    int Wysokosc_;
    sf::Vector2f Srodek_;
};

#endif // MENU_H
