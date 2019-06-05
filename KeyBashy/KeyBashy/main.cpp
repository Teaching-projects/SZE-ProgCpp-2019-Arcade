#include <SFML/Graphics.hpp>
#include "BashyTerminal.h"
#include <iostream>
#include "Enemy1.h"
#include "Collider.h"

bool GameOver = false;

int main()
{
	//az ablak nem teljesen jól nyílik meg, más megoldást keresni maybe.
	int ScreenWidth = sf::VideoMode::getDesktopMode().width;
	int ScreenHeight = sf::VideoMode::getDesktopMode().height;
	
	sf::RenderWindow window(sf::VideoMode(), "KeyBashy", sf::Style::Close | sf::Style::Titlebar | sf::Style::Fullscreen);
	
	//sf::Vertex line [] = {sf::Vertex(sf::Vector2f(0,ScreenHeight/2)),sf::Vertex(sf::Vector2f(ScreenWidth,ScreenHeight/2)) };

	sf::String playerInput;

	sf::Font font;

	sf::Text playerText;
	sf::Text text;

	font.loadFromFile("arial.ttf");
	playerText.setFont(font);
	playerText.setFillColor(sf::Color::White);
	playerText.setCharacterSize(15);
	playerText.setPosition(500, 500);

	sf::Texture terminalTexture;
	sf::Texture enemy1Texture;
	sf::Texture enemy2Texture;

	
	

	enemy1Texture.loadFromFile("SpriteSheets/enemy1.png");
	enemy2Texture.loadFromFile("SpriteSheets/enemy1.png");

	terminalTexture.loadFromFile("SpriteSheets/terminal.png");

	BashyTerminal Bashy(window,&terminalTexture,sf::Vector2u(2,1),0.30f,700.0f); //tesztek animáció / mozgás kurzorokkal

	Enemy1 enemy1(&enemy1Texture,sf::Vector2u(2,1),0.30f,350.0f,100.0f,100.0f);
	Enemy1 enemy2(&enemy2Texture, sf::Vector2u(2, 1), 0.30f, 250.0f,300.0f,300.0f);
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
			if (event.type == sf::Event::TextEntered)
			{

				playerInput += event.text.unicode;
				playerText.setString(playerInput);
				
			}
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		Bashy.Update(deltaTime,GameOver,window);
		enemy1.Update(deltaTime,Bashy.GetBody(),GameOver);
		enemy2.Update(deltaTime,Bashy.GetBody(),GameOver);

		//Bashy.GetCollider().CheckCollision(enemy1.GetCollider(), 0.0f); Collision nem is kell egyenlõre!
		//Bashy.GetCollider().CheckCollision(enemy2.GetCollider(), 0.0f);
		//enemy1.GetCollider().CheckCollision(enemy2.GetCollider(), 0.0f);
		//enemy2.GetCollider().CheckCollision(enemy1.GetCollider(), 0.0f);
		//update utan kell ütközest nezni!
		//if (Bashy.GetCollider().CheckCollision(enemy1.GetCollider(),4) && GameOver != true) {
		
			//GameOver = true;
			//std::cout << "Game Over";
		
		//}
			
		 //kire csekkoljam a collidert az enemyre or mindig a fõhõsre hmmm
		// screen törlése mielott kirajzolom az újakat
		window.clear();
		
		// kirajzolás
		Bashy.Draw(window);
		enemy1.Draw(window);
		enemy2.Draw(window);
		window.draw(playerText);
		//window.draw(line,4,sf::Lines);

		// window megjelenités
		window.display();
	}
}