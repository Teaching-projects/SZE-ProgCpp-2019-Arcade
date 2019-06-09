#include "StageTest.h"

TestStage::TestStage() {

	GameOver = false;

	selected = 1;

	srand(time(0)); //randomhoz az idõt beállitani

	spawnTimeLimit = 0.05f; //mennyi idõnként éledjenek a randomok
	
	if (!font.loadFromFile("arial.ttf")) {
	
	
	}

	playerText.setFont(font);
	playerText.setFillColor(sf::Color::White); //a text input formátum
	playerText.setCharacterSize(25);
	playerText.setString("");
							
	enemy1Texture.loadFromFile("SpriteSheets/enemy1.png"); //  spritesheetek betöltése
	terminalTexture.loadFromFile("SpriteSheets/terminal.png"); //

	
	//enemy1List.push_back(new Enemy1(&enemy1Texture, sf::Vector2u(2, 2),0.0f,0.0f,150.0f,font));

}

int TestStage::Start(sf::RenderWindow& window) {

	GameOver = false;
	playerText.setPosition(0, window.getSize().y - 30);
	enemy1List.clear();
	window.clear();
	playerText.setString("");
	 //Text input format
	BashyTerminal Bashy(window, &terminalTexture, sf::Vector2u(2, 1), 600.0f); //hero

	while (window.isOpen())
	{
		if (GameOver != true) {

			spawnTimeLimit = spawnClock.getElapsedTime().asSeconds();

			if (spawnTimeLimit >= 0.5) {

				enemy1List.push_back(new Enemy1(&enemy1Texture, sf::Vector2u(2, 2), font));

				spawnClock.restart();

			}

		}
		else {
		
			GameOvertext.setCharacterSize(40);
			GameOvertext.setString("GAME OVER");
			GameOvertext.setFont(font);
			GameOvertext.setFillColor(sf::Color::Red);
			GameOvertext.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / (2 + 1) * 1));

			GameOvertext2.setCharacterSize(30);
			GameOvertext2.setString("You died, restart ('r') / quit ('q') ?");
			GameOvertext2.setFont(font);
			GameOvertext2.setFillColor(sf::Color::Red);
			GameOvertext2.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / (2 + 1) * 2));

		}

		//system("CLS");
		//std::cout << teszttime;
		deltaTime = clock.restart().asSeconds();

		sf::Event event;

		while (window.pollEvent(event))
		{
			if (!GameOver) {
				if (event.type == sf::Event::TextEntered)
				{
					//std::cout << "size: " << enemy1List.size();
					playerInput += event.text.unicode;
					playerText.setString(playerInput);
					for (int i = 0; i < enemy1List.size(); i++) {
						if (enemy1List.at(i)->text.getString() == playerInput) {
							enemy1List.at(i)->state = Dying;
							enemy1List.at(i)->Update(deltaTime, Bashy.GetBody(), GameOver);
							//std::cout << "size: " << enemy1List.size();
							playerInput = "";
							playerText.setString(playerInput);
						}
					}

				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {

					for (int i = 0; i < enemy1List.size(); i++) {
						if (enemy1List.at(i)->text.getString() == playerInput) {
							enemy1List.at(i)->state = Dying;
							enemy1List.at(i)->Update(deltaTime, Bashy.GetBody(), GameOver);
							//std::cout << "size: " << enemy1List.size();
						}
					}
					playerInput = "";
					playerText.setString(playerInput);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) { //karaktertörlés

					playerInput = playerText.getString().substring(0, playerText.getString().getSize() - 1);
					playerText.setString(playerInput);
				}
			}
			else {
				
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
				
					selected = 1;

					window.clear();

					return selected;

				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
				
					selected = 0;
					for (int i = 0; i < enemy1List.size(); i++)
					{
						delete enemy1List.at(i);
						//enemy1List.erase(enemy1List.begin() + i);
					}
					

					return selected;
				
				}
			
			}
			if (event.type == sf::Event::Closed)
				window.close();
		}

		Bashy.Update(deltaTime, GameOver, window);

		for (size_t i = 0; i < enemy1List.size(); i++)
		{
			switch (enemy1List.at(i)->state) {

			case Alive:
				enemy1List.at(i)->Update(deltaTime, Bashy.GetBody(), GameOver);
				if (enemy1List.at(i)->GetCollider().CheckCollision(Bashy.GetCollider()) && GameOver != true) {

					GameOver = true;

					//std::cout << "Game Over";

				}
				break;

			case Dying:

				enemy1List.at(i)->state = Dead;

				break;
			case Dead:

				delete enemy1List.at(i);
				enemy1List.erase(enemy1List.begin() + i);

				break;
			}
		}


		//for (int i = 0; i < enemy1List.size(); i++) {
		//	enemy1List.at(i)->Update(deltaTime, Bashy.GetBody(), GameOver);
		//	
		//	if (Bashy.GetCollider().CheckCollision(enemy1List.at(i)->GetCollider(),4) && GameOver != true) {

		//	GameOver = true;
		//	break;
		//	//std::cout << "Game Over";

		//	}
		//}

		// screen törlése mielott kirajzolom az újakat
		window.clear();

		// kirajzolás
		Bashy.Draw(window);
		for (int i = 0; i < enemy1List.size(); i++) {

			enemy1List.at(i)->Draw(window);

		}
		if(GameOver){
			window.draw(GameOvertext);
			window.draw(GameOvertext2);
		}
		window.draw(playerText);

		// window megjelenités
		window.display();
	}

	return selected;
}