#include "menu.h"

    menu::menu(std::string direction)
    {
        set_texture(direction);

        if (direction == "grafiki/guzik4.png")
        {
            Bohater.setOrigin(23, 11);
        }
        else Bohater.setOrigin(119/ 2, 10);

        Bohater.setScale(3,3);
        Srodek_.x = 640;
        Srodek_.y = 200;
        Bohater.setPosition(Srodek_);
    }

    menu::~menu()
    {
    }
    void menu::draw(sf::RenderTarget& target, sf::RenderStates state) const
    {
        target.draw(this->Bohater, state);
    }

    void menu::set_position(float iks, float igrek)
    {
        Bohater.setPosition(iks, igrek);
        Srodek_.x = Bohater.getPosition().x;
        Srodek_.y = Bohater.getPosition().y;

    }
    void menu::set_texture(std::string tex)
    {
        NazwaTekstury_ = tex;
        TexturaBohatera_.loadFromFile(NazwaTekstury_);
        Bohater.setTexture(TexturaBohatera_);

    }
    sf::Sprite menu:: Zwroc_bohatera()
    {
        return Bohater;
    }
