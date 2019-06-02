#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class BashyTerminal
{

public:
	BashyTerminal(sf::Texture *terminalTexture,sf::Vector2u imageCount, float switchTime,float speed);
	

	void Draw(sf::RenderWindow& window);
	void Update(float uTime);

private:

	
	sf::RectangleShape body;
	float speed;
	std::string health;
	unsigned int row;
	Animation animation;
};

