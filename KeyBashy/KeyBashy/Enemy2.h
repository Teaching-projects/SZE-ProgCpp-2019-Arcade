#pragma once
#include <SFML/Graphics.hpp>
#include "BasicEnemy.h"
#include "Animation.h"
#include "Collider.h"
#include <stdlib.h>

class Enemy2 : public BasicEnemy
{
	public:
		//virtual ~Enemy2() = default;
		
		Enemy2(sf::Texture* Enemy2Texture, sf::Vector2u imageCount, sf::Font& font, float speed, bool k);

		Enemy2(sf::Texture* Enemy2Texture, sf::Vector2u imageCount, sf::Font& font,float speed);

		Enemy2(sf::Texture* Enemy2Texture, sf::Vector2u imageCount, float x, float y, float speed, sf::Font& font);

		void Update(float uTime, sf::RectangleShape Bashybody, bool GameOver);

		Collider GetCollider() { return Collider(body); }
		

	private:

		
		bool canmove;

		float x = 0.0f;
		float y = 0.0f;
		
		char c;
		std::string asd;
		//sf::RectangleShape body;
		float speed;
		
		sf::Clock moveClock;

		unsigned int row;
		Animation animation;
	
};
