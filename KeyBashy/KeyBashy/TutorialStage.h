#pragma once
#include <SFML\Graphics.hpp>
#include "BasicEnemy.h"
#include <string>
#include <Windows.h>
#include "BashyTerminal.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Enemy3.h"


class TutorialStage
{
public:

	TutorialStage();

	int checkEnemyList(sf::Event &event, BashyTerminal& Bashy);

	int Start(sf::RenderWindow& window, BashyTerminal& Bashy);

	void sleep(int t);

	void printTextCbyC(std::string String,int& n);

	void printOutNintendoStyle(std::string message, int& n);

	sf::Texture Enemy2Texture;
	sf::Texture Enemy1Texture;
	sf::Texture Enemy3Texture;
private:
	
	sf::String playerInput; //
	sf::Text playerText;	//  a text inputhoz
	sf::Text GameOvertext;			//
	sf::Font font;			//
	sf::Text GameOvertext2;

	std::vector <BasicEnemy*> enemy1List;
	std::vector <Enemy3*> enemy3List;

	sf::Text actualMessage;
	bool printed = false;

	int selected;
	int scene;
	float deltaTime;

	sf::Clock clock;
	sf::Clock messageClock;
};

