#include "Menu.h"
#include <Windows.h>

Menu::Menu(float width, float height) {

	selected = 1;

	if (!font.loadFromFile("cmd.ttf")) {

	}

	menuElements[0].setFont(font);
	menuElements[0].setFillColor(sf::Color::White);
	menuElements[0].setString("Exit");
	menuElements[0].setPosition(sf::Vector2f(width / 2, height / (NUMOFMENUELEMENTS + 1) * 2));
	menuElements[0].setCharacterSize(25);

	menuElements[1].setFont(font);
	menuElements[1].setFillColor(sf::Color::Green);
	menuElements[1].setString("Play");
	menuElements[1].setPosition(sf::Vector2f(width / 2, height / (NUMOFMENUELEMENTS + 1) * 1));
	menuElements[1].setCharacterSize(25);

	menuElements[selected].setOutlineColor(sf::Color::Green);
	menuElements[selected].setOutlineThickness(1);
}

int Menu::Start(sf::RenderWindow& window)
{

	while (window.isOpen())
	{
		

		
		sf::Event event;

		while (window.pollEvent(event))
		{
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

				if (selected == 0) {
				
					menuElements[selected].setFillColor(sf::Color::White);
					menuElements[selected].setOutlineThickness(0);
					selected += 1;
					menuElements[selected].setFillColor(sf::Color::Green);
					menuElements[selected].setOutlineColor(sf::Color::Green);
					menuElements[selected].setOutlineThickness(1);
				}
				else {
					menuElements[selected].setFillColor(sf::Color::White);
					menuElements[selected].setOutlineThickness(0);
					selected -= 1;
					menuElements[selected].setFillColor(sf::Color::Green);
					menuElements[selected].setOutlineColor(sf::Color::Green);
					menuElements[selected].setOutlineThickness(1);
				}

			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {

				if (selected == 1) {
					menuElements[selected].setFillColor(sf::Color::White);
					menuElements[selected].setOutlineThickness(0);

					selected -= 1;
					menuElements[selected].setFillColor(sf::Color::Green);
					menuElements[selected].setOutlineColor(sf::Color::Green);
					menuElements[selected].setOutlineThickness(1);
					
				}
				else {
					menuElements[selected].setFillColor(sf::Color::White);
					menuElements[selected].setOutlineThickness(0);
					selected = 1;
					menuElements[selected].setFillColor(sf::Color::Green);
					menuElements[selected].setOutlineColor(sf::Color::Green);
					menuElements[selected].setOutlineThickness(1);
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			
				Sleep(100);
				return selected;
				
			}
			if (event.type == sf::Event::Closed)
				window.close();

		}
		//Update

		window.clear();

		// kirajzolás
		for (int i = 0; i < NUMOFMENUELEMENTS;i++) {
			
			window.draw(menuElements[i]);

		}
		
		// window megjelenités
		window.display();
	}

	return 0;
}
