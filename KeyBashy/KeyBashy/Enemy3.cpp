#include "Enemy3.h"

Enemy3::Enemy3(sf::Texture& Enemy3Texture, float x, float y, float speed){

	row = 0; //Animációhoz
	this->speed = speed;
	body.setSize(sf::Vector2f(300.0f, 300.0f));
	body.setOrigin(body.getSize() / 2.0f);
	this->y = y;
	if((rand() % 2) == 0) {
	
		
		sprite.setPosition(0, this->y);
		left = true;
		sprite.setTexture(Enemy3Texture);
	}
	else
	{
		
		sprite.setScale(-1.f, 1.f);
		left = false;
		sprite.setPosition(2000, this->y);
		
		

	}
	state = Play;

	
	
}

void Enemy3::Update(float deltaTime, sf::Font &font) {

	sf::Vector2f movement(0.0f, 0.0f);

	if (left && sprite.getPosition().x > 2100) {
	
		state = Stop;
	}
	else if (!left && sprite.getPosition().x<-10) {
	
		state = Stop;

	}


	if (left) {
		movement.x += (speed * deltaTime);

		sprite.move(movement);
	}
	else {
	
		movement.x -= (speed * deltaTime);

		sprite.move(movement);
	
	}

}
void Enemy3::Draw(sf::RenderWindow& window) {

	
	window.draw(sprite);
}