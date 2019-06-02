#include <SFML/Graphics.hpp>
#include "BashyTerminal.h"
#include <iostream>
#include "Enemy1.h"

int main()
{
	//az ablak nem teljesen jól nyílik meg, más megoldást keresni maybe.
	int ScreenWidth = sf::VideoMode::getDesktopMode().width;
	int ScreenHeight = sf::VideoMode::getDesktopMode().height;

	sf::RenderWindow window(sf::VideoMode(ScreenWidth, ScreenHeight), "KeyBashy", sf::Style::Close | sf::Style::Titlebar);

	sf::Texture terminalTexture;
	sf::Texture enemy1Texture;

	enemy1Texture.loadFromFile("SpriteSheets/enemy1.png");
	
	terminalTexture.loadFromFile("SpriteSheets/terminal.png");

	BashyTerminal Bashy(&terminalTexture,sf::Vector2u(2,1),0.30f,700.0f); //tesztek animáció / mozgás kurzorokkal

	Enemy1 enemy1(&enemy1Texture,sf::Vector2u(2,1),0.30f,700.0f);

	float deltaTime = 0.0f;
	sf::Clock clock;
	
	//minél több annál smoothabb ofc
	window.setFramerateLimit(200);
	
	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		
		sf::Event event;

		while (window.pollEvent(event))
		{
			
			if (event.type == sf::Event::Closed)
				window.close();
		}
		 
		Bashy.Update(deltaTime);
		enemy1.Update(deltaTime);
		// screen törlése mielott kirajzolom az újakat
		window.clear();
		
		// kirajzolás
		Bashy.Draw(window);
		enemy1.Draw(window);

		// window megjelenités
		window.display();
	}
}