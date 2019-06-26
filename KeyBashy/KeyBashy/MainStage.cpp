#pragma once
#include "MainStage.h"

void MainStage::SpawnEnemies(float numOfSeconds) {

	int a;

	if (spawnEnemy.getElapsedTime().asSeconds() > numOfSeconds) {
		
		a = (rand() % 2) + 1;

		if (a == 1) {
			enemy1List.push_back(new Enemy2(&Enemy2Texture, sf::Vector2u(2, 2), font, 400.0f));
			enemy1List.push_back(new Enemy2(&Enemy2Texture, sf::Vector2u(2, 2), font, 400.0f));
		}
		else {
			enemy1List.push_back(new Enemy1(&Enemy1Texture, sf::Vector2u(2, 2), font));
			enemy1List.push_back(new Enemy1(&Enemy1Texture, sf::Vector2u(2, 2), font));
		}

		
		spawnEnemy.restart();
	}

}

void MainStage::sleep(int t) { Sleep(t); }

MainStage::MainStage() {

	srand(time(0));
	GameOver = false;
	Enemy1Texture.loadFromFile("SpriteSheets/enemy1.png");
	Enemy2Texture.loadFromFile("SpriteSheets/enemy2.png");
	Enemy3Texture.loadFromFile("SpriteSheets/rocket.png");
	BossTexture.loadFromFile("SpriteSheets/boss.png");
	Enemy3LeftTexture.loadFromFile("SpriteSheets/rocketleft.png");

	font.loadFromFile("cmd.ttf");
	playerText.setFont(font);
	playerText.setFillColor(sf::Color::White); //a text input formátum
	playerText.setCharacterSize(25);
	//playerText.setString("");

	selected = 1;
}

void MainStage::printOutNintendoStyle(std::string message,int& n) {

	if (messageClock.getElapsedTime().asMilliseconds() > 50) {

		if (n < message.length()) {
			
			actualMessage.setString(actualMessage.getString()+message.at(n));
			messageClock.restart();

			n++;
		}
		else if(messageClock.getElapsedTime().asMilliseconds() > 700){
			actualMessage.setString("");
			scene++;
			n = 0;
		}
	}

}

int MainStage::checkEnemyList(sf::Event& event, BashyTerminal& Bashy) {

	int hitnumber = 0; //volt hit ?

	for (int i = 0; i < enemy1List.size(); i++) {
		if (enemy1List.at(i)->getText().getString() == playerInput) {
			enemy1List.at(i)->state = Dying;
			enemy1List.at(i)->Update(deltaTime, Bashy.GetBody(), GameOver);
			//std::cout << "size: " << enemy1List.size();
			playerInput = "";
			playerText.setString(playerInput);
			hitnumber++;
		}
	}
	return hitnumber;

}

int MainStage::Start(sf::RenderWindow& window, BashyTerminal& Bashy) {

	sf::Clock enemy3clock;
	enemy3clock.restart();

	spawnEnemy.restart().asSeconds();

	actualMessage.setFont(font);
	actualMessage.setFillColor(sf::Color::White);
	actualMessage.setPosition(800.0f, 400.0f);
	actualMessage.setCharacterSize(30);

	

	scene = 0;

	int n = 0;

	int hitnumber = 0;

	bool enough = false; //ne spawnoljon több //ÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁTIASIOFJSDFIJOGSDIKOPLF

	bool endStage = false;


	GameOver = false;
	playerText.setPosition(0, window.getSize().y - 30);
	enemy1List.clear();
	window.clear();
	playerInput = "";
	playerText.setString(playerInput);
	//playerText.setString("");

	while (window.isOpen())
	{

		/*if (!sentence1printed)
		{

			printOutNintendoStyle(sentence,n);

		}
		else {

			enemy1List.push_back(new Enemy2(&Enemy2Texture, sf::Vector2u(2, 2),1800.0f,500.0f,200.0f,font));

		}*/
		if (GameOver != true && endStage != true) {


			switch (scene) {

			case 0:
				//printOutNintendoStyle("FIGHT!", n);
				printOutNintendoStyle("Lets see what you are made of Bashy...",n);
				enough = false;
				break;
			case 1:
				if (hitnumber < 4) {
					SpawnEnemies(3);
				}
				else {
					hitnumber = 0;
					scene++;
					
				}

				break;
			case 2:
				if (hitnumber<5) {
					if (enemy3clock.getElapsedTime().asSeconds() > 1) {
						enemy3List.push_back(new Enemy3(&Enemy3Texture, &Enemy3LeftTexture, Bashy.body.getPosition().x, Bashy.body.getPosition().y, 1400.0f));
						enemy3clock.restart();
					}
				}
				else {
					hitnumber = 0;
					scene++;
				}
				enough = false;
				break;
			case 3:

				if (!enough) {

					enemy1List.push_back(new Enemy2(&BossTexture, sf::Vector2u(1, 1), font, 220.0f, true));
					
					enough = true;
				}
				SpawnEnemies(7);
				if (hitnumber < 1000) {
					if (enemy3clock.getElapsedTime().asSeconds() > 3) {
						enemy3List.push_back(new Enemy3(&Enemy3Texture, &Enemy3LeftTexture, Bashy.body.getPosition().x, Bashy.body.getPosition().y, 1500.0f));
						enemy3clock.restart();
					}
				}
				break;
			case 4:
				endStage = true;
				break;
			}
		}
		else {

			if (GameOver) {
				GameOvertext.setCharacterSize(40);
				GameOvertext.setString("GAME OVER");
				GameOvertext.setFont(font);
				GameOvertext.setFillColor(sf::Color::Red);
				GameOvertext.setPosition(sf::Vector2f((window.getSize().x / 2) - 200, window.getSize().y / (2 + 1) * 1));

				GameOvertext2.setCharacterSize(30);
				GameOvertext2.setString("You died, restart ('r') / quit ('q') ?");
				GameOvertext2.setFont(font);
				GameOvertext2.setFillColor(sf::Color::Red);
				GameOvertext2.setPosition(sf::Vector2f((window.getSize().x / 2) - 200, window.getSize().y / (2 + 1) * 2));
			}
			else if (endStage) {


				GameOvertext.setCharacterSize(40);
				GameOvertext.setString("Stage Done, Damn you're good...");
				GameOvertext.setFont(font);
				GameOvertext.setFillColor(sf::Color::Green);
				GameOvertext.setPosition(sf::Vector2f((window.getSize().x / 2) - 200, window.getSize().y / (2 + 1) * 1));

				GameOvertext2.setCharacterSize(30);
				GameOvertext2.setString("Restart('r'), quit('q')?");
				GameOvertext2.setFont(font);
				GameOvertext2.setFillColor(sf::Color::Green);
				GameOvertext2.setPosition(sf::Vector2f((window.getSize().x / 2) - 200, window.getSize().y / (2 + 1) * 2));

			}
		}

		deltaTime = clock.restart().asSeconds();

		sf::Event event;

		while (window.pollEvent(event))
		{
			if (!GameOver && !endStage) {
				if (event.type == sf::Event::TextEntered)
				{
					playerInput += event.text.unicode;
					playerText.setString(playerInput);
					
					checkEnemyList(event, Bashy);

				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) { //ENTER NYOMÓS LEGYEN VAGY CSAK SIMA PÖTYÖGÕS

					playerInput = "";
					playerText.setString(playerInput);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) { //backspace mûködtetése

					playerInput = playerText.getString().substring(0, playerText.getString().getSize() - 1);
					playerText.setString(playerInput);
				}
			}
			else {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {

					selected = 2;

					window.clear();

					return selected;

				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {

					selected = 0;
					for (int i = 0; i < enemy1List.size(); i++)
					{
						delete enemy1List.at(i);
						//enemy1List.erase(enemy1List.begin() + i); nemtudom 4 sure hogy kell e?
					}


					return selected;

				}
				if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Return))) {

					selected = 2;

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
				if (enemy1List.at(i)->GetCollider().CheckCollision(Bashy.GetCollider()) && GameOver != true && endStage != true) {
					GameOver = true;
				}

				break;

			case Dying:

				enemy1List.at(i)->state = Dead;

				break;
			case Dead:
				if (enemy1List.at(i)->boss == true) {
				
					endStage = true;
				}
				delete enemy1List.at(i);
				enemy1List.erase(enemy1List.begin() + i);
				hitnumber++;
				
				break;
			}
		}
		for (size_t i = 0; i < enemy3List.size(); i++)
		{
			enemy3List.at(i)->Update(deltaTime, font);
			if (enemy3List.at(i)->GetCollider().CheckCollision(Bashy.GetCollider()) && GameOver != true) {

				GameOver = true;

			}
		}
		for (int i = 0; i < enemy3List.size(); i++) { //RAKÉTA delete
			if (enemy3List.at(i)->state == Stop) {
				delete enemy3List.at(i);
				enemy3List.erase(enemy3List.begin() + i);
				hitnumber++;
				
			}
		}



		// screen törlése mielott kirajzolom az újakat
		window.clear();

		// kirajzolás
		Bashy.Draw(window);
		//gg.Draw(window);
		if (enemy3List.size() > 0) { //RAKÉTA DRAW
			for (size_t i = 0; i < enemy3List.size(); i++)
			{
				enemy3List.at(i)->Draw(window);
			}
		}

		if (enemy1List.size() > 0) {

			for (int i = 0; i < enemy1List.size(); i++) {

				enemy1List.at(i)->Draw(window);

			}
		}
		if (GameOver || endStage) {
			window.draw(GameOvertext);
			window.draw(GameOvertext2);
		}
		window.draw(playerText);
		window.draw(actualMessage);
		// window megjelenités
		window.display();
	}


	return 0;
}
