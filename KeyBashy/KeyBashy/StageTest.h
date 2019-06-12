#pragma once
#include <SFML/Graphics.hpp>
#include "BashyTerminal.h"
#include "BasicEnemy.h"

class TestStage
{
public:
	TestStage();

	int Start(sf::RenderWindow &window, BashyTerminal& Bashy);

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


	float deltaTime = 0.0f; //animációhoz az eltelt idõ

	sf::Clock clock; //deltatimehoz kell, mozgáshoz

	sf::Clock spawnClock; //Spawnclock
	float spawnTimeLimit; //hány secenként spawnoljanak enemyk
	//float deleteTimeLimit;
	//frame rate minél több annál smoothabb ofc
};

