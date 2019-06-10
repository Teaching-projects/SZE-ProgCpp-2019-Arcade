#pragma once
#include <SFML/Graphics.hpp>
#include "BashyTerminal.h"
#include "BasicEnemy.h"

class TestStage
{
public:
	TestStage();

	int Start(sf::RenderWindow &window);

private:

	bool GameOver;

	sf::String playerInput; //
	sf::Text playerText;	//  a text inputhoz
	sf::Text GameOvertext;			//
	sf::Font font;			//
	sf::Text GameOvertext2;

	std::vector <BasicEnemy*> enemy1List; //az enemy1 - k containere

	sf::Texture terminalTexture;					// Spritesheetek
	sf::Texture enemy1Texture;						//
	sf::Texture enemy2Texture;

	int selected;


	float deltaTime = 0.0f; //anim�ci�hoz az eltelt id�

	sf::Clock clock; //deltatimehoz kell, mozg�shoz

	sf::Clock spawnClock; //Spawnclock
	float spawnTimeLimit; //h�ny secenk�nt spawnoljanak enemyk
	//float deleteTimeLimit;
	//frame rate min�l t�bb ann�l smoothabb ofc
};

