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

class Enemy1
{
	public:
		Enemy1(sf::Texture* terminalTexture, sf::Vector2u imageCount, float x, float y, sf::Font& font);

		void Draw(sf::RenderWindow& window);
		void Update(float uTime, sf::RectangleShape Bashybody,bool GameOver);

		Collider GetCollider() { return Collider(body); }

public:

	sf::Text text;
	State state;
	private:

		bool left;
		char asd;
		sf::RectangleShape body;
		float speed;
		std::string health;
		unsigned int row;
		Animation animation;

};




