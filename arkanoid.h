#pragma once
#include "menu.h"
#include "pilka.h"
using namespace sf;
using namespace std;

class arkanoid
{
public:
	arkanoid(int rodzaj, float x,float y)
	{
		poziom = rodzaj;
		k1.loadFromFile("grafiki/k1.png");
		k2.loadFromFile("grafiki/k2.png");
		k3.loadFromFile("grafiki/k3.png");

		switch (poziom)
		{
			case 1:
			{
				kostka.setTexture(k1);
				break;
			}
			case 2:
			{
				kostka.setTexture(k2);
				break;
			}
			case 3:
			{
				kostka.setTexture(k3);
				break;
			}
		}

		kostka.setOrigin(40,15);
		kostka.setScale(1,1);
		kostka.setPosition(x, y);
	}
	int ileHp()
	{
		return poziom;
	}
	void aktualizuj()
	{
		switch (poziom)
		{
		case 1:
		{
			kostka.setTexture(k1);
			break;
		}
		case 2:
		{
			kostka.setTexture(k2);
			break;
		}
		case 3:
		{
			kostka.setTexture(k3);
			break;
		}
		}
	}
	void kolizja(Pilka &pil)
	{
		if (kostka.getGlobalBounds().intersects(pil.boundpilki()))
		{
			pil.setMinusVelocity();
			poziom -= 1;
		}
	}
	~arkanoid()
	{

	}
	void rysuj(RenderWindow &okno)
	{

		okno.draw(kostka);
	}
private:
	Sprite kostka;
	Texture k1, k2, k3;
	int poziom, drop;

};




