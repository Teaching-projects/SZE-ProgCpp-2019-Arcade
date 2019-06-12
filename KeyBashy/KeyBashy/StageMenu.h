#pragma once
#include <SFML/Graphics.hpp>

class StageMenu 
{


public:

	StageMenu();

	int Start(sf::RenderWindow& window);

private:

	int selectedStage;
	int selected;
	sf::Font font;
	sf::Text menuElements[2];

};

