#include "StageMenu.h"

StageMenu::StageMenu() {

	selected = 1;
	selectedStage = 1;
	if (!font.loadFromFile("cmd.ttf")) {

	}

	menuElements[0].setFont(font);
	menuElements[0].setFillColor(sf::Color::White);
	menuElements[0].setString("Tutorial Stage");
	
	menuElements[0].setCharacterSize(50);

	menuElements[1].setFont(font);
	menuElements[1].setFillColor(sf::Color::Green);
	menuElements[1].setString("Stage 1");
	
	menuElements[1].setCharacterSize(50);

	menuElements[selected].setOutlineColor(sf::Color::Green);
	menuElements[selected].setOutlineThickness(1);
}

int StageMenu::Start(sf::RenderWindow& window)
{
	window.clear();
	menuElements[0].setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / (2 + 1) * 2));
	menuElements[1].setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / (2 + 1) * 1));
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


				return (selected+1);

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				
				return 0;
			
			}
			if (event.type == sf::Event::Closed)
				window.close();

		}
		//Update

		window.clear();

		// kirajzolás
		for (int i = 0; i < 2; i++) {

			window.draw(menuElements[i]);

		}

		// window megjelenités
		window.display();
	}

}