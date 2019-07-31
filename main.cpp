#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
#include<ctime>
#include<cmath>
#include<vector>
#include<Windows.h>
#include <list>
#include "menu.h"
#include "paletka.h"
#include "przeszkody.h"
#include "pilka.h"
#include "arkanoid.h"
using namespace std;

int licznik;
bool tryb1 = false, tryb2 = false, tryb3 = false;
bool animate1 = false;
bool animate2 = false;

void timer() {
    if (licznik == 310) {
        licznik = 0;
    }
    licznik++;
}

int ile_guzikow = 4;
bool men = true;
sf::Vector2f pozycja_myszy;
std::vector<menu> guziki;
std::list<arkanoid*> ark;
void zrob_mapke()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			int zm;
			if (i == 0) zm = 3;
			if (i == 1 && j < 7 && j>2) zm = 3;
			if (i == 2 && j < 7 && j>2) zm = 3;
			if (i == 1 && (j <= 2 || j >= 7)) zm = 2;
			if (i == 2 && (j <= 2 || j >= 7)) zm = 2;
			if (i == 3) zm = 2;
			if (i == 4)zm = 1;
			arkanoid *niu = new arkanoid(zm,40+j*80,15+i*30);
			ark.push_back(niu);
		}
	}
}
void wyswietl_mapke(RenderWindow &okno)
{
	for (auto i = ark.begin(); i != ark.end(); i++)
	{
		(*i)->rysuj(okno);
	}
}
bool kolizja_myszki(menu x)
{


    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {

        if (x.Zwroc_bohatera().getGlobalBounds().contains(pozycja_myszy))
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    else
        return false;



}
void zbijanie_kostek(Pilka &x)
{
	for (auto i = ark.begin(); i != ark.end();)
	{
		(*i)->kolizja(x);
		(*i)->aktualizuj();
		if ((*i)->ileHp() <= 0)
		{
			i = ark.erase(i);
		}
		else i++;
	}
}
void dodaj_guziki()
{

    for (int i = 0; i < ile_guzikow; i++)
    {



        string direction = "grafiki/guzik" + to_string(i + 1);
        direction += ".png";
        menu *temp = new menu(direction);
        temp->set_position(400, 240 + 100 * i);
        guziki.push_back(*temp);
    }
}
vector<przeszkody>wektor;

int main() {
    sf::Texture tex_tlo_menu,tex_tlo_gry_1;
    tex_tlo_menu.loadFromFile("grafiki/tlo_menu.png");
    tex_tlo_gry_1.loadFromFile("grafiki/tlo_gry1.png");
    sf::Sprite tlo_menu(tex_tlo_menu);
    sf::Sprite tlo_gry_1(tex_tlo_gry_1);
    tlo_menu.setScale(2.53, 2.53);
    tlo_gry_1.setScale(2.53,2.53);
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window"); //(szerokosc,dlugosc)
    Paletka p("grafiki/paletka1.png"); //gracz
    Pilka pi;
    Paletka p1("grafiki/paletka2.png"); //stworzenie bota
    p1.pozycja(400,15);
    bool czy1 = false;   // jesli falsz to pilka sledzi paletke, jesli true to zaczyna sie poruszac i sa kolizje , jesli spadnie , znow falsz
    pi.set_velocity_x(-200); //predkosc x
    pi.set_velocity_y(-300);
    sf::Clock clock;
    window.setFramerateLimit(60); // ustawione stałe fps
    dodaj_guziki();
	zrob_mapke();
	while (window.isOpen()) {
		window.clear(sf::Color::White);
		sf::Event event;
		while (window.pollEvent(event)) {
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
		pozycja_myszy.x = sf::Mouse::getPosition(window).x;
		pozycja_myszy.y = sf::Mouse::getPosition(window).y;
		if (men) {
			window.draw(tlo_menu);
			for (int i = 0; i < ile_guzikow; i++) // wyswietlanie guzikow
			{

				window.draw(guziki[i]);
				//sprawdzamy czy guzik zostal wcisniety
				if (kolizja_myszki(guziki[i]))
				{

					if (i == 0)
					{
						men = false;
						tryb1 = true;
						Sleep(100);
					}
					else if (i == 1)
					{
						men = false;
						tryb2 = true;
						Sleep(100);
					}
					else if (i == 2)
					{
						men = false;
						tryb3 = true;
						Sleep(100);
					}
					else if (i == 3)
					{
						window.close();
					}
				}


			}
		}
		else if ((men == false) && (tryb1 == true)) {
			window.draw(tlo_gry_1);
			float delta = float(clock.getElapsedTime().asSeconds());
			std::cout << delta << std::endl;
			clock.restart();
			timer();


			pi.animate();


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				p.ruch(-500, 0, delta);
				if (p.bound().left <= 0) {
					p.pozycja(150, 585);
				}
				pi.pozycjakulki(p.nadajpozycjex(), p.nadajpozycjey() - 70, czy1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				p.ruch(500, 0, delta);
				if (p.bound().left + p.bound().width >= 800) {
					p.pozycja(650, 585);
				}
				pi.pozycjakulki(p.nadajpozycjex(), p.nadajpozycjey() - 70, czy1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				czy1 = true; // uruchamianie ruchu pilki
			}
			//tworzenie przeszkod
			if (licznik == 300) {
				przeszkody temp;
				wektor.push_back(temp);
			}

			for (auto itr = wektor.begin(); itr != wektor.end();) {
				(*itr).rysowaniep(window);
				(*itr).obrot(100, delta);
				pi.kolizja(czy1, (*itr).boundprzeszkody()); //kolizja miedzy pilka a przeszkodami, jesli dotknie to znikaja
				if ((*itr).znikanieprzeszkody(pi.boundpilki()) == true) {
					itr = wektor.erase(itr);
				}
				else itr++;

			}
			pi.ruch(delta, czy1, p.bound(), p1.bound()); // ruch pilki

			p1.pozycja(pi.nadajpozycjex(), 15); //nadanie pozycji botowi

			if (pi.boundpilki().top + pi.boundpilki().height >= 600) { // falsz jesli spadnie , wracanie do punktu wyjscia
				czy1 = false;
				if (czy1 == false) {
					pi.pozycjakulki(p.nadajpozycjex(), p.nadajpozycjey() - 70, czy1);

				}
			}

			p.rysowaniep(window);
			p1.rysowaniep(window);
			pi.rysowanie(window);


		}
		else if ((men == false) && (tryb2 == true)) {
			float delta = float(clock.getElapsedTime().asSeconds());
			std::cout << delta << std::endl;
			clock.restart();
			timer();


			window.draw(tlo_gry_1);

			pi.animate();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				p.ruch(-500, 0, delta);
				if (p.bound().left <= 0) {
					p.pozycja(150, 585);
				}
				pi.pozycjakulki(p.nadajpozycjex(), p.nadajpozycjey() - 70, czy1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				p.ruch(500, 0, delta);
				if (p.bound().left + p.bound().width >= 800) {
					p.pozycja(650, 585);
				}
				pi.pozycjakulki(p.nadajpozycjex(), p.nadajpozycjey() - 70, czy1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				p1.ruch(-500, 0, delta);
				if (p1.bound().left <= 0) {
					p1.pozycja(150, 15);
				}
				//  pi.pozycjakulki(p.nadajpozycjex(), p.nadajpozycjey() - 70, czy1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				p1.ruch(500, 0, delta);
				if (p1.bound().left + p.bound().width >= 800) {
					p1.pozycja(650, 15);
				}
				// pi.pozycjakulki(p.nadajpozycjex(), p.nadajpozycjey() - 70, czy1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				czy1 = true; // uruchamianie ruchu pilki
			}
			//tworzenie przeszkod
			if (licznik == 300) {
				przeszkody temp;
				wektor.push_back(temp);
			}

			for (auto itr = wektor.begin(); itr != wektor.end();) {
				(*itr).rysowaniep(window);
				(*itr).obrot(100, delta);
				pi.kolizja(czy1, (*itr).boundprzeszkody()); //kolizja miedzy pilka a przeszkodami, jesli dotknie to znikaja
				if ((*itr).znikanieprzeszkody(pi.boundpilki()) == true) {
					itr = wektor.erase(itr);
				}
				else itr++;

			}
			pi.ruchdo1v1(delta, czy1, p.bound(), p1.bound()); // ruch pilki



			if (pi.boundpilki().top + pi.boundpilki().height >= 600) { // falsz jesli spadnie , wracanie do punktu wyjscia
				czy1 = false;
				if (czy1 == false) {
					pi.pozycjakulki(p.nadajpozycjex(), p.nadajpozycjey() - 70, czy1);

				}
			}
			if (pi.boundpilki().top <= 0) { // falsz jesli spadnie , wracanie do punktu wyjscia
				czy1 = false;
				if (czy1 == false) {
					pi.pozycjakulki(p1.nadajpozycjex(), p1.nadajpozycjey() + 30, czy1);

				}
			}
			p.rysowaniep(window);
			p1.rysowaniep(window);
			pi.rysowanie(window);
		}
		else if ((men == false) && (tryb3 == true)) {
		p1.pozycja(-100, -100);
		if (ark.empty()) men = true;
			window.draw(tlo_gry_1);
			float delta = float(clock.getElapsedTime().asSeconds());
			std::cout << delta << std::endl;
			clock.restart();
			timer();
			pi.animate();
			wyswietl_mapke(window);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				p.ruch(-500, 0, delta);
				if (p.bound().left <= 0) {
					p.pozycja(150, 585);
				}
				pi.pozycjakulki(p.nadajpozycjex(), p.nadajpozycjey() - 70, czy1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				p.ruch(500, 0, delta);
				if (p.bound().left + p.bound().width >= 800) {
					p.pozycja(650, 585);
				}
				pi.pozycjakulki(p.nadajpozycjex(), p.nadajpozycjey() - 70, czy1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				czy1 = true; // uruchamianie ruchu pilki
			}

			pi.ruch(delta, czy1, p.bound(), p1.bound());
			if (pi.boundpilki().top + pi.boundpilki().height >= 600) { // falsz jesli spadnie , wracanie do punktu wyjscia
				czy1 = false;
				if (czy1 == false) {
					pi.pozycjakulki(p.nadajpozycjex(), p.nadajpozycjey() - 70, czy1);

				}
			}
			zbijanie_kostek(pi);
			p.rysowaniep(window);
			//p1.rysowaniep(window);
			pi.rysowanie(window);
			
		}
		window.display();
	}
    return 0;
}
