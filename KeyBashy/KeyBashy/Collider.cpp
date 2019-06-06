#include "Collider.h"
#include <iostream>

Collider::Collider(sf::RectangleShape& body)
	:body(body)
{



}

bool Collider::CheckCollision(Collider other) //T�glalapok �sszehasonlitasa
{

	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f) { //egym�sba van a k�t object , gg end

		//push = std::min(std::max(push, 0.0f), 1.0f);

		/*if (intersectX > intersectY)
		{

			if (deltaX > 0.0f) {
			
				Move(intersectX * (1.0f - push), 0.0f);
				other.Move(-intersectX* push, 0.0f);

			}
			else {
			

				Move(-intersectX * (1.0f - push), 0.0f);
				other.Move(intersectX * push, 0.0f);
			
			}
			if (deltaY > 0.0f) {

				Move(intersectY * (1.0f - push), 0.0f);
				other.Move(-intersectY * push, 0.0f);

			}
			else {


				Move(0.0f,-intersectY * (1.0f - push));
				other.Move(0.0f, intersectY * push);
			}

		}*/

		return true;
	}

	return false;
}
