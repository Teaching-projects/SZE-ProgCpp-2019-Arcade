#pragma once
#include "Enemy2.h"

Enemy2::Enemy2(sf::Texture* Enemy2Texture, sf::Vector2u imageCount, sf::Font& font, float speed,bool boss) : animation(Enemy2Texture, imageCount) {//inicializálás list 

	this->speed = speed;
	row = 0;
	this->boss = boss;
	body.setSize(sf::Vector2f(500.0f, 300.0f));
	body.setOrigin(body.getSize() / 2.0f);

	
	state = Alive;
	for (size_t i = 0; i < 13; i++)
	{
		c = rand() % 25 + 1;
		c += 97;
		asd += c;
	}


	moveClock.restart().asSeconds();
	canmove = true; //a mozgás az elején true

	body.setPosition(x, y);
	body.setTexture(Enemy2Texture);

	text.setFont(font); //Enemyk hp stringje
	text.setString(asd);
	text.setFillColor(sf::Color::Magenta);
	text.setCharacterSize(60);
	text.setPosition(body.getPosition());
}

Enemy2::Enemy2(sf::Texture* Enemy2Texture, sf::Vector2u imageCount, sf::Font& font, float speed) : animation(Enemy2Texture, imageCount) {//inicializálás list 
	boss = false;
	this->speed = ((rand() % 70) + 1) + speed;
	row = 0;
	
	body.setSize(sf::Vector2f(60.0f, 42.0f));
	body.setOrigin(body.getSize() / 2.0f);

	x = rand() % 2300 + 1;

	if (300 < x && x < 1500) {

		y = rand() % 2 + 1;
		if (y == 1)
			y = (rand() % 200 + 1) + 800;
		else
			y = (rand() % 200 + 1);
	}
	else
	{
		y = rand() % 1500 + 1;

	}
	state = Alive;
	for (size_t i = 0; i < 3; i++)
	{
		c = rand() % 25 + 1;
		c += 97;
		asd += c;
	}
		
		
	moveClock.restart().asSeconds();
	canmove = true; //a mozgás az elején true

	body.setPosition(x, y);
	body.setTexture(Enemy2Texture);

	text.setFont(font); //Enemyk hp stringje
	text.setString(asd);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(40);
	text.setPosition(body.getPosition());
}

Enemy2::Enemy2(sf::Texture* Enemy2Texture, sf::Vector2u imageCount, float x, float y, float speed, sf::Font& font) : animation(Enemy2Texture, imageCount)
{
	boss = false;
	this->x = x;
	this->y = y;
	this->speed = speed;
	row = 0;
	
	body.setSize(sf::Vector2f(200.0f, 200.0f));
	body.setOrigin(body.getSize() / 2.0f);

	state = Alive;
	asd = rand() % 25 + 1;
	asd += 97;

	this->speed = speed;

	body.setPosition(x, y);
	body.setTexture(Enemy2Texture);
	text.setFont(font);
	text.setString(asd);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(40);
	text.setPosition(body.getPosition());

}

void Enemy2::Update(float deltaTime, sf::RectangleShape Bashybody, bool GameOver) {

	sf::Vector2f movement(0.0f, 0.0f);

	if (canmove && moveClock.getElapsedTime().asSeconds() > 0.8) {
		
		canmove = false;
		moveClock.restart().asSeconds();
	
	}
	else if(!canmove && moveClock.getElapsedTime().asSeconds() > 0.8){
	
		canmove = true;
		moveClock.restart().asSeconds();
	}

	if (!GameOver && state == Alive && canmove) {
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

	if (state == Alive && canmove && this->boss == true) {
		animation.Update(row, deltaTime, 0.30f);
		body.setTextureRect(animation.uvRect);
		body.move(movement);
		text.setPosition(body.getPosition().x-165, body.getPosition().y+150);

	}
	else if (state == Alive && canmove) {
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