#include "Enemy3.h"

Enemy3::Enemy3(sf::Texture* Enemy3Texture, sf::Vector2u imageCount, float x, float y, float speed):animation(Enemy3Texture, imageCount){

	row = 0; //Animációhoz
	this->speed = speed;
	body.setSize(sf::Vector2f(300.0f, 300.0f));
	body.setOrigin(body.getSize() / 2.0f);


	state = Play;

	this->y = y;
	body.setPosition(0, this->y);
	body.setTexture(Enemy3Texture);

	/*text.setFont(font);
	text.setString(asd);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(25);
	text.setPosition(body.getPosition());*/

}

void Enemy3::Update(float deltaTime, sf::Font &font) {

	sf::Vector2f movement(0.0f, 0.0f);

	if (body.getPosition().x > 2100) {
	
		state = Stop;
	}

	movement.x += (speed * deltaTime);

		body.move(movement);
		

}
void Enemy3::Draw(sf::RenderWindow& window) {

	
	window.draw(body);
}