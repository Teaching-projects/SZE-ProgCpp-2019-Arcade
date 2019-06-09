#include <SFML/Graphics.hpp>

#define NUMOFMENUELEMENTS  2

class Menu
{

public:

	Menu(float width, float height);

	int Start(sf::RenderWindow& window);

private:

	int selected;
	sf::Font font;
	sf::Text menuElements[NUMOFMENUELEMENTS];
};

