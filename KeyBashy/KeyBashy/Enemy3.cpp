#include "Enemy3.h"

Enemy3::Enemy3(sf::Texture* Enemy3Texture, sf::Texture* Enemy3LeftTexture , float x, float y, float speed){

	row = 0; //Animációhoz
	this->speed = speed;
	body.setSize(sf::Vector2f(300.0f, 300.0f));
	body.setOrigin(body.getSize() / 2.0f);
	this->y = y;
	if((rand() % 2) == 0) {
	
		
		body.setPosition(0, this->y);
		left = true;
		body.setTexture(Enemy3Texture);
	}
	else
	{
		
		
		left = false;
		body.setPosition(2000, this->y);
		body.setTexture(Enemy3LeftTexture);
		

	}
	state = Play;

	
	
}

void Enemy3::Update(float deltaTime, sf::Font &font) {

	sf::Vector2f movement(0.0f, 0.0f);

	if (left && body.getPosition().x > 2100) {
	
		state = Stop;
	}
	else if (!left && body.getPosition().x<-10) {
	
		state = Stop;

	}


	if (left) {
		movement.x += (speed * deltaTime);

		body.move(movement);
	}
	else {
	
		movement.x -= (speed * deltaTime);

		body.move(movement);
	
	}

}
void Enemy3::Draw(sf::RenderWindow& window) {

	
	window.draw(body);
}