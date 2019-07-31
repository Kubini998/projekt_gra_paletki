#include "paletka.h"

Paletka::Paletka(std::string direction) {
        tex.loadFromFile(direction);
        paletka.setTexture(tex);
        paletka.setScale(6,3);
        paletka.setOrigin(26, 6);
        paletka.setPosition(400, 585);
    }
    void Paletka:: rysowaniep(sf::RenderWindow &w) {
        w.draw(paletka);
    }
    void Paletka::pozycja(float x, float y) {
        paletka.setPosition(x, y);
    }
    float Paletka::nadajpozycjex() {
        float x = paletka.getPosition().x;
        return x;
    }
    float Paletka::nadajpozycjey() {
        float y = paletka.getPosition().y;
        return y;
    }
    void Paletka::ruch(float x, float y, float delta) {
        paletka.move(x*delta, y*delta);
    }
    sf::FloatRect Paletka::bound() {
        sf::FloatRect bound = paletka.getGlobalBounds();
        return bound;
    }


