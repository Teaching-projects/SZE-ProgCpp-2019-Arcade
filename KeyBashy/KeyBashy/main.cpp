#include <SFML/Graphics.hpp>
#include "BashyTerminal.h"
#include <iostream>
#include "Enemy1.h"
#include "Collider.h"

int main()
{
	//az ablak nem teljesen j�l ny�lik meg, m�s megold�st keresni maybe.
	int ScreenWidth = sf::VideoMode::getDesktopMode().width;
	int ScreenHeight = sf::VideoMode::getDesktopMode().height;

	sf::RenderWindow window(sf::VideoMode(ScreenWidth, ScreenHeight), "KeyBashy", sf::Style::Close | sf::Style::Titlebar);

	sf::Texture terminalTexture;
	sf::Texture enemy1Texture;

	enemy1Texture.loadFromFile("SpriteSheets/enemy1.png");
	
	terminalTexture.loadFromFile("SpriteSheets/terminal.png");

	BashyTerminal Bashy(window,&terminalTexture,sf::Vector2u(2,1),0.30f,700.0f); //tesztek anim�ci� / mozg�s kurzorokkal

	Enemy1 enemy1(&enemy1Texture,sf::Vector2u(2,1),0.30f,300.0f);

	float deltaTime = 0.0f;
	sf::Clock clock;
	
	//min�l t�bb ann�l smoothabb ofc
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
		enemy1.Update(deltaTime,Bashy.GetBody());
		//update utan kell �tk�zest nezni!
		Bashy.GetCollider().CheckCollision(enemy1.GetCollider()); //kire csekkoljam a collidert az enemyre or mindig a f�h�sre hmmm
		// screen t�rl�se mielott kirajzolom az �jakat
		window.clear();
		
		// kirajzol�s
		Bashy.Draw(window);
		enemy1.Draw(window);

		// window megjelenit�s
		window.display();
	}
}