#include "Enemy1.h"

Enemy1::Enemy1(sf::Texture* terminalTexture, sf::Vector2u imageCount, float switchTime, float speed, float x, float y) : animation(terminalTexture, imageCount, switchTime) {//inicializ�l�s list 

	this->speed = speed;
	row = 0;
	left = false;
	body.setSize(sf::Vector2f(73.0f, 55.0f));
	body.setOrigin(body.getSize()/2.0f);
	body.setPosition(x,y);

	body.setTexture(terminalTexture);

	font.loadFromFile("arial.ttf");
	text.setFont(font);
	text.setString("asdsafdsf");
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(25);
	text.setPosition(body.getPosition());
}

void Enemy1::Draw(sf::RenderWindow& window) {

	window.draw(body);
	window.draw(text);
}

void Enemy1::Update(float deltaTime, sf::RectangleShape Bashybody,bool GameOver) {
	
	sf::Vector2f movement(0.0f, 0.0f);

	if (!GameOver) {
		if ((Bashybody.getPosition().x) <= this->body.getPosition().x)
			movement.x -= (speed * deltaTime);
		else
			movement.x += (speed * deltaTime);
		if ((Bashybody.getPosition().y) <= this->body.getPosition().y)
			movement.y -= (speed * deltaTime);
		else
			movement.y += (speed * deltaTime);
	}
	animation.Update(row, deltaTime);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
	text.setPosition(body.getPosition().x-7,body.getPosition().y+45);
}