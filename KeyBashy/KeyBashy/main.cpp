#include <SFML/Graphics.hpp>
#include "BashyTerminal.h"
#include <iostream>
#include "Enemy1.h"
#include "Collider.h"
#include <stdlib.h>
#include <time.h>
#include <thread>
#include <windows.h>


bool GameOver = false;

int main()
{
	//az ablak nem teljesen j�l ny�lik meg, m�s megold�st keresni maybe / fullscreen megold�s
	int ScreenWidth = sf::VideoMode::getDesktopMode().width;
	int ScreenHeight = sf::VideoMode::getDesktopMode().height;

	sf::RenderWindow window(sf::VideoMode(), "KeyBashy", sf::Style::Close | sf::Style::Titlebar | sf::Style::Fullscreen);

	srand(time(0)); //randomhoz az id�t be�llitani

	sf::String playerInput; //
	sf::Text playerText;	//  a text inputhoz
	sf::Text text;			//
	sf::Font font;			//
	font.loadFromFile("arial.ttf");

	playerText.setFont(font);
	playerText.setFillColor(sf::Color::White);
	playerText.setCharacterSize(25);
	playerText.setPosition(0, window.getSize().y - 30); //Text input format

	sf::Texture terminalTexture;					//
	sf::Texture enemy1Texture;							//  spritesheetek bet�lt�se
	enemy1Texture.loadFromFile("SpriteSheets/enemy1.png"); //
	terminalTexture.loadFromFile("SpriteSheets/terminal.png"); //


	BashyTerminal Bashy(window, &terminalTexture, sf::Vector2u(2, 1), 550.0f); //hero

	std::vector <Enemy1*> enemy1List; //az enemy1 - k containere


	enemy1List.push_back(new Enemy1(&enemy1Texture, sf::Vector2u(2, 2),font));
	//enemy1List.push_back(new Enemy1(&enemy1Texture, sf::Vector2u(2, 2),0.0f,0.0f,150.0f,font));

	float deltaTime = 0.0f; //anim�ci�hoz az eltelt id�

	sf::Clock clock; //deltatimehoz kell, mozg�shoz

	//sf::Clock deleteTimer;

	sf::Clock spawnClock; //Spawnclock
	float spawnTimeLimit; //h�ny secenk�nt spawnoljanak enemyk
	//float deleteTimeLimit;
	//frame rate min�l t�bb ann�l smoothabb ofc
	window.setFramerateLimit(200);

	while (window.isOpen())
	{
		if (GameOver != true) {
			spawnTimeLimit = spawnClock.getElapsedTime().asSeconds();

			if (spawnTimeLimit >= 0.5) {

					enemy1List.push_back(new Enemy1(&enemy1Texture, sf::Vector2u(2, 2), font));

					spawnClock.restart();

				}

			}

			//system("CLS");
			//std::cout << teszttime;
			deltaTime = clock.restart().asSeconds();

			sf::Event event;

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::TextEntered)
				{
					//std::cout << "size: " << enemy1List.size();
					playerInput += event.text.unicode;
					playerText.setString(playerInput);
					for (int i = 0; i < enemy1List.size(); i++) {
						if (enemy1List.at(i)->text.getString() == playerInput) {
							enemy1List.at(i)->state = Dying;
							enemy1List.at(i)->Update(deltaTime, Bashy.GetBody(), GameOver);
							//std::cout << "size: " << enemy1List.size();
							playerInput = "";
							playerText.setString(playerInput);
						}
					}

				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {

					for (int i = 0; i < enemy1List.size(); i++) {
						if (enemy1List.at(i)->text.getString() == playerInput) {
							enemy1List.at(i)->state = Dying;
							enemy1List.at(i)->Update(deltaTime, Bashy.GetBody(), GameOver);
							//std::cout << "size: " << enemy1List.size();
						}
					}
					playerInput = "";
					playerText.setString(playerInput);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) { //karaktert�rl�s

					playerInput = playerText.getString().substring(0, playerText.getString().getSize() - 1);
					playerText.setString(playerInput);
				}
				if (event.type == sf::Event::Closed)
					window.close();
			}

			Bashy.Update(deltaTime, GameOver, window);

			for (size_t i = 0; i < enemy1List.size(); i++)
			{
				switch (enemy1List.at(i)->state) {

				case Alive:
					enemy1List.at(i)->Update(deltaTime, Bashy.GetBody(), GameOver);
					if (enemy1List.at(i)->GetCollider().CheckCollision(Bashy.GetCollider()) && GameOver != true) {

						GameOver = true;

						//std::cout << "Game Over";

					}
					break;

				case Dying:

					enemy1List.at(i)->state = Dead;

					break;
				case Dead:

					delete enemy1List.at(i);
					enemy1List.erase(enemy1List.begin()+i);

					break;
				}
			}


			//for (int i = 0; i < enemy1List.size(); i++) {
			//	enemy1List.at(i)->Update(deltaTime, Bashy.GetBody(), GameOver);
			//	
			//	if (Bashy.GetCollider().CheckCollision(enemy1List.at(i)->GetCollider(),4) && GameOver != true) {

			//	GameOver = true;
			//	break;
			//	//std::cout << "Game Over";

			//	}
			//}

			// screen t�rl�se mielott kirajzolom az �jakat
			window.clear();

			// kirajzol�s
			Bashy.Draw(window);
			for (int i = 0; i < enemy1List.size(); i++) {

				enemy1List.at(i)->Draw(window);

			}

			window.draw(playerText);

			// window megjelenit�s
			window.display();
		}
	}