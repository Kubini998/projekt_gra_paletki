#ifndef PILKA_H
#define PILKA_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<string>

class Pilka
{
public:
    Pilka() ;
    
    void animate() {
        if (animate1)
        {
            pilka.rotate(2);
        }
        else if (animate2)
        {
            pilka.rotate(-2);
        }
    }
	void setMinusVelocity()
	{
		velocity_x_ *= -1;
		velocity_y_ *= -1;
	}
    float set_velocity_x(float v_x);
    float set_velocity_y(float v_y);
    void rysowanie(sf::RenderWindow &w);
    void pozycjakulki(float x, float y, bool czy);
    void ustawteksturke(std::string direction);
    void ruch(float delta, bool czy, sf::FloatRect obiekt, sf::FloatRect obiekt1);
    void ruchdo1v1(float delta, bool czy, sf::FloatRect obiekt, sf::FloatRect obiekt1);
    void kolizja(bool czy, sf::FloatRect obiekt);
    sf::FloatRect boundpilki();
    float nadajpozycjex() ;
private:
    sf::Sprite pilka;
    sf::Texture tex,tex2;
	bool animate1 = true, animate2 = false;
    float velocity_x_;
    float velocity_y_;

};

#endif // PILKA_H
