#include "przeszkody.h"

przeszkody:: przeszkody() {
    przeszkoda.setSize(sf::Vector2f(20, 20));
    przeszkoda.setOrigin(10, 10);
    przeszkoda.setPosition(rand() % 801, rand() % 500);
    przeszkoda.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));

}
void przeszkody::rysowaniep(sf::RenderWindow &w) {
    w.draw(przeszkoda);
}
void przeszkody::obrot(float g, float delta) {
    przeszkoda.rotate(g*delta);
}
sf::FloatRect przeszkody::boundprzeszkody() {
    sf::FloatRect bound = przeszkoda.getGlobalBounds();
    return bound;
}
bool przeszkody::znikanieprzeszkody(sf::FloatRect obiekt) {
    if (przeszkoda.getGlobalBounds().intersects(obiekt)) {
        przeszkoda.setSize(sf::Vector2f(0, 0));
        return true;
    }
    else return false;
}
