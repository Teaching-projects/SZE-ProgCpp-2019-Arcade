#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Enemy1
{
	public:
		Enemy1(sf::Texture* terminalTexture, sf::Vector2u imageCount, float switchTime, float speed);


		void Draw(sf::RenderWindow& window);
		void Update(float uTime);

	private:

		sf::Font font;
		sf::Text text;
		sf::RectangleShape body;
		float speed;
		std::string health;
		unsigned int row;
		Animation animation;
};




