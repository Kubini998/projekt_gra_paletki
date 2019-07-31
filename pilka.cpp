#include "pilka.h"

Pilka:: Pilka() {
    tex.loadFromFile("grafiki/pilka.png");
    tex2.loadFromFile("grafiki/pilka2.png");
    pilka.setTexture(tex);
    pilka.setScale(40/23, 40/23);
    pilka.setOrigin(13, 13);
    pilka.setPosition(400, 515);

}
/* nie wiem
 * void animate() {
    if (animate1)
    {
        pilka.rotate(2);
    }
    else if (animate2)
    {
        pilka.rotate(-2);
    }
}
*/
float Pilka::set_velocity_x(float v_x) {
    velocity_x_ = v_x;
    return v_x;
}
float Pilka::set_velocity_y(float v_y) {
    velocity_y_ = v_y;
    return v_y;
}

void Pilka::rysowanie(sf::RenderWindow &w) {
    w.draw(pilka);
}
void Pilka::pozycjakulki(float x, float y, bool czy) {
    if (czy == false) {
        pilka.setPosition(x, y);
    }
}
void Pilka::ustawteksturke(std::string direction) {


}
void Pilka::ruch(float delta, bool czy, sf::FloatRect obiekt, sf::FloatRect obiekt1) {
    sf::FloatRect bounds = pilka.getGlobalBounds();
    if (czy == true) {

        if (bounds.left <= 0)
        {
            //  velocity_y_ = fabs(velocity_y_);
            velocity_x_ = fabs(velocity_x_);
        }
        if (bounds.top <= 0)
        {
            velocity_y_ = fabs(velocity_y_);
            //   velocity_x_ = fabs(velocity_x_);

        }
        if (bounds.left + bounds.width >= 800)
        {
            //   velocity_y_ = -fabs(velocity_y_);
            velocity_x_ = -fabs(velocity_x_);
        }
        if (bounds.intersects(obiekt))
        {
            //  velocity_x_ = -fabs(velocity_x_);
            pilka.setTexture(tex);
            animate1 = true;
            animate2 = false;
            velocity_y_ = -fabs(velocity_y_);
        }
        if (bounds.intersects(obiekt1))
        {
            pilka.setTexture(tex2);
            animate1 = false;
                animate2 = true;
            velocity_x_ = fabs(velocity_x_);
            velocity_y_ = fabs(velocity_y_);
        }

        pilka.move(velocity_x_*delta, velocity_y_*delta);
    }

}
void Pilka::ruchdo1v1(float delta, bool czy, sf::FloatRect obiekt, sf::FloatRect obiekt1) {
    sf::FloatRect bounds = pilka.getGlobalBounds();
    if (czy == true) {

        if (bounds.left <= 0)
        {
            //  velocity_y_ = fabs(velocity_y_);
            velocity_x_ = fabs(velocity_x_);
        }

        if (bounds.left + bounds.width >= 800)
        {
            //   velocity_y_ = -fabs(velocity_y_);
            velocity_x_ = -fabs(velocity_x_);
        }
        if (bounds.intersects(obiekt))
        {
            //  velocity_x_ = -fabs(velocity_x_);
            pilka.setTexture(tex);
            animate1 = true;
            animate2 = false;
            velocity_y_ = -fabs(velocity_y_);
        }
        if (bounds.intersects(obiekt1))
        {
            pilka.setTexture(tex2);
            animate1 = false;
                animate2 = true;
            velocity_x_ = fabs(velocity_x_);
            velocity_y_ = fabs(velocity_y_);
        }

        pilka.move(velocity_x_*delta, velocity_y_*delta);
    }

}

void Pilka::kolizja(bool czy, sf::FloatRect obiekt) {
    sf::FloatRect bounds = pilka.getGlobalBounds();
    if (czy == true) {
        if (bounds.intersects(obiekt)) {
            velocity_x_ = -velocity_x_;
            velocity_y_ = -velocity_y_;
        }
        //pilka.move(velocity_x_*delta,velocity_y_*delta);
    }
}
sf::FloatRect Pilka::boundpilki() {

    sf::FloatRect bound = pilka.getGlobalBounds();
    return bound;
}


float Pilka::nadajpozycjex() {
    float x = pilka.getPosition().x;
    return x;
}
