#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "StageLoader.h"

int main()
{
	
	//az ablak nem teljesen jól nyílik meg, más megoldást keresni maybe / fullscreen megoldás
	int ScreenWidth = sf::VideoMode::getDesktopMode().width;
	int ScreenHeight = sf::VideoMode::getDesktopMode().height;

	int state = 2;

	sf::RenderWindow window(sf::VideoMode(), "KeyBashy", sf::Style::Close | sf::Style::Titlebar | sf::Style::Fullscreen);

	window.setFramerateLimit(200);

	StageLoader play;
	Menu menu(ScreenWidth, ScreenHeight);

	while(state != 0)

		switch (state) {
		
		case 0: 
			
				break;
			
		case 1:

			state = play.loadStage(1,window);
			break;
			

		case 2:
			
			state = menu.Start(window);
			break;
		}
	
	window.close();
	return 0;
	}