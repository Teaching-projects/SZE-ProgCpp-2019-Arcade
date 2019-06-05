#pragma once

#include <SFML\Graphics.hpp>
#include "Collider.h"

class Platform
{
public:

	void Draw(sf::RenderWindow& window);

	Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position) {
	
		body.setSize(size);
		body.setOrigin(size/2.0f);
		body.setTexture(texture);
		body.setPosition(position);

	}

	Collider Getcollider() { return Collider(body); }

private:
	sf::RectangleShape body;
};

