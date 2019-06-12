#pragma once
#include "Animation.h"
#include "Collider.h"

enum Drawable {

	Play,
	Stop

};

class Enemy3
{

public:
	//virtual ~Enemy2() = default;

	//Enemy3(sf::Texture* Enemy2Texture, sf::Vector2u imageCount, sf::Font& font, float speed);

	Enemy3(sf::Texture* Enemy2Texture, sf::Vector2u imageCount, float x, float y, float speed);

	void Update(float uTime, sf::Font &font);

	Collider GetCollider() { return Collider(body); }

	void Draw(sf::RenderWindow& window);
	Drawable state;

private:

	float x;
	float y;
	
	float speed;
	sf::RectangleShape body;
	unsigned int row;
	Animation animation;

};

