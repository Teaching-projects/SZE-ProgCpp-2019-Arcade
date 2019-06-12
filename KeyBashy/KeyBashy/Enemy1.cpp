#include "Enemy1.h"

Enemy1::Enemy1(sf::Texture* terminalTexture, sf::Vector2u imageCount,sf::Font& font) : animation(terminalTexture, imageCount) {//inicializálás list 
	//random elhelyezésnek új konstruktor...
	
	row = 0;
	left = false;
	body.setSize(sf::Vector2f(60.0f, 42.0f));
	body.setOrigin(body.getSize()/2.0f);

	x = rand() % 2300 +1;

	if (300<x && x<1500) {
		
		y = rand() % 1 + 1;
		if(y == 1)
			y = (rand() % 200 + 1)+800;
		else
			y = (rand() % 200 + 1);
	}
	else
	{
		y = rand() % 1500 + 1;

	}
	state = Alive;

	for (size_t i = 0; i < 4; i++)
	{
		c = rand() % 25 + 1;
		c += 97;
		asd += c;
	}
	
	this->speed = ((rand() % 70) + 1) + 300;

	body.setPosition(x,y);
	body.setTexture(terminalTexture);
	text.setFont(font);
	text.setString(asd);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(40);
	text.setPosition(body.getPosition());
}

Enemy1::Enemy1(sf::Texture* terminalTexture, sf::Vector2u imageCount, float x, float y, float speed ,sf::Font& font) : animation(terminalTexture, imageCount)
{

	this->x = x;
	this->y = y;
	this->speed = speed;
	row = 0;
	left = false;
	body.setSize(sf::Vector2f(200.0f, 200.0f));
	body.setOrigin(body.getSize() / 2.0f);

	state = Alive;
	asd = rand() % 25 + 1;
	asd += 97;

	this->speed = speed;

	body.setPosition(x, y);
	body.setTexture(terminalTexture);
	text.setFont(font);
	text.setString(asd);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(40);
	text.setPosition(body.getPosition());

}

void Enemy1::Update(float deltaTime, sf::RectangleShape Bashybody,bool GameOver) {
	
	sf::Vector2f movement(0.0f, 0.0f);

	if (!GameOver && state == Alive) {
		if ((Bashybody.getPosition().x) <= this->body.getPosition().x)
			movement.x -= (speed * deltaTime);
		else
			movement.x += (speed * deltaTime);
		if ((Bashybody.getPosition().y) <= this->body.getPosition().y)
			movement.y -= (speed * deltaTime);
		else
			movement.y += (speed * deltaTime);
	}

	//melyik animáció legyen

	if (state == Alive) {
		animation.Update(row, deltaTime, 0.30f);
		body.setTextureRect(animation.uvRect);
		body.move(movement);
		text.setPosition(body.getPosition().x - 7, body.getPosition().y + 45);
		
	}
	else if (state == Dying) {
		
		row = 1;
		animation.Update(row, deltaTime, 0.30f);
		body.setTextureRect(animation.uvRect);
		
	}

}