#include "Collider.h"
#include <iostream>

Collider::Collider(sf::RectangleShape& body)
	:body(body)
{



}

bool Collider::CheckCollision(Collider other) //Téglalapok összehasonlitasa
{

	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f) { //egymásba van a két object , gg end

		system("CLS");
		std::cout << "GAME OVER";

		return true;
	}

	return false;
}
