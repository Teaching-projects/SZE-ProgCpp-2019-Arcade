#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"
#include <stdlib.h>

enum State
{
	Alive,
	Dying,
	Dead
};

class Enemy2
{

	
	public:
		Enemy2(sf::Texture* Enemy2Texture, sf::Vector2u imageCount, sf::Font& font);

		Enemy2(sf::Texture* Enemy2Texture, sf::Vector2u imageCount, float x, float y, float speed, sf::Font& font);

		void Draw(sf::RenderWindow& window);
		void Update(float uTime, sf::RectangleShape Bashybody, bool GameOver);

		Collider GetCollider() { return Collider(body); }

	public:

		sf::Text text;
		State state;

	private:

		float x = 0.0f;
		float y = 0.0f;
		bool left;
		char asd;
		sf::RectangleShape body;
		float speed;
		std::string health;
		unsigned int row;
		Animation animation;
	
};
