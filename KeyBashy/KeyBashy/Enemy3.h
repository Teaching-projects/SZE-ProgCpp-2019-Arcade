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

	Enemy3(sf::Texture& Enemy3Texture, float x, float y, float speed);

	void Update(float uTime, sf::Font &font);

	Collider GetCollider() { return Collider(sprite); }

	void Draw(sf::RenderWindow& window);
	Drawable state;

private:

	sf::Sprite sprite;
	float x;
	float y;
	bool left;
	float speed;
	//sf::RectangleShape body;
	unsigned int row;

};

