#pragma once
#include <SFML/Graphics.hpp>
#include "Collider.h"

enum State
{
	Alive,
	Dying,
	Dead
};

class BasicEnemy
{
public:
	sf::Text text;
	State state;
public:
	bool boss;
	void Draw(sf::RenderWindow& window);

	void virtual Update(float uTime, sf::RectangleShape Bashybody, bool GameOver) = 0;

	Collider GetCollider() { return Collider(body); }
	
	sf::Text getText() { return this->text; }
	
protected:

	sf::RectangleShape body;
};

