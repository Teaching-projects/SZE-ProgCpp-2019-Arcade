#include "BashyTerminal.h"

	BashyTerminal::BashyTerminal(sf::Texture *terminalTexture,sf::Vector2u imageCount, float switchTime, float speed) : animation(terminalTexture, imageCount, switchTime) {//inicializálás list 

		this->speed = speed;
		row = 0;

		body.setSize(sf::Vector2f(73.0f,47.0f));

		body.setPosition(0.0f,0.0f);

		body.setTexture(terminalTexture);

	}

	void BashyTerminal::Draw(sf::RenderWindow& window) {
	
		window.draw(body);
	
	}

	void BashyTerminal::Update(float deltaTime) {
		
		sf::Vector2f movement(0.0f,0.0f);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			movement.y -= speed*deltaTime;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			movement.y += speed * deltaTime;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			movement.x -= speed * deltaTime;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			movement.x += speed * deltaTime;
		animation.Update(row,deltaTime);
		body.setTextureRect(animation.uvRect);
		body.move(movement);
	}