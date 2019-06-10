#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"
#include <stdlib.h>
#include "BasicEnemy.h"



class Enemy1 : public BasicEnemy
{
	public:


		virtual ~Enemy1() = default;

		Enemy1(sf::Texture* terminalTexture, sf::Vector2u imageCount,sf::Font& font);

		Enemy1(sf::Texture* terminalTexture, sf::Vector2u imageCount,float x,float y, float speed,sf::Font& font);

		//void Draw(sf::RenderWindow& window);
		void Update(float uTime, sf::RectangleShape Bashybody,bool GameOver);

		Collider GetCollider() { return Collider(body); }

public:

	//sf::Text text;
	
	
private:
		
		float x = 0.0f;
		float y = 0.0f;
		bool left;
		char asd;
		//sf::RectangleShape body;
		float speed;
		std::string health;
		unsigned int row;
		Animation animation;

};




