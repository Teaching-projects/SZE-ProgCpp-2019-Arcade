#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"

class BashyTerminal
{

public:
	BashyTerminal(sf::RenderWindow& window,sf::Texture *terminalTexture,sf::Vector2u imageCount,float speed);
	

	void Draw(sf::RenderWindow& window);
	void Update(float uTime,bool GameOver,sf::RenderWindow& window);

	Collider GetCollider() { return Collider(body); }

	sf::RectangleShape GetBody() { return this->body; };

	sf::RectangleShape body;
private:

	float speed;
	std::string health;
	unsigned int row;
	Animation animation;
};

