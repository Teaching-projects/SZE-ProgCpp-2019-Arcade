#pragma once
#include "TutorialStage.h"


bool GameOver = false;

void TutorialStage::sleep(int t) { Sleep(t); }

TutorialStage::TutorialStage() {

	srand(time(0));

	Enemy1Texture.loadFromFile("SpriteSheets/enemy1.png");
	Enemy2Texture.loadFromFile("SpriteSheets/enemy2.png");
	Enemy3Texture.loadFromFile("SpriteSheets/rocket.png");

	font.loadFromFile("cmd.ttf");
	playerText.setFont(font);
	playerText.setFillColor(sf::Color::White); //a text input form�tum
	playerText.setCharacterSize(25);
	//playerText.setString("");

	selected = 1;
}

void TutorialStage::printTextCbyC(std::string String,int& n) { //maga a sztring �s hogy eddig h�nyat irtunk ki

	if (n < String.length()) {
		sleep(35);
		actualMessage.setString(actualMessage.getString() + String[n]);
		n++;
		printed = false;
	}
	else {
		sleep(1500);
		scene++;
		actualMessage.setString("");
		n = 0;
		printed = true;

	}
}

int TutorialStage::checkEnemyList(sf::Event& event, BashyTerminal& Bashy) {
	
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

int TutorialStage::Start(sf::RenderWindow& window, BashyTerminal& Bashy) {

	actualMessage.setFont(font);
	actualMessage.setFillColor(sf::Color::White);
	actualMessage.setPosition(800.0f, 400.0f);
	actualMessage.setCharacterSize(30);

	scene = 0;

	int n = 0;

	int hitnumber = 0;

	bool enough = true; //ne spawnoljon t�bb //�������������������������TIASIOFJSDFIJOGSDIKOPLF

	bool endStage = false;
	
	//bool sentence1printed = false;
	std::string sentence = "Hello Bashy! Let's see how fast you can write.";
	//Enemy2 gg(&Enemy2Texture, sf::Vector2u(2, 2), font);
	
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

			printTextCbyC(sentence,n);

		}
		else {

			enemy1List.push_back(new Enemy2(&Enemy2Texture, sf::Vector2u(2, 2),1800.0f,500.0f,200.0f,font));

		}*/
		if (GameOver != true && endStage != true) {


			switch (scene) {

			case 0:
				printTextCbyC(sentence, n);
				enough = false;
				break;
			case 1:
				if (!enough) {
					enemy1List.push_back(new Enemy2(&Enemy2Texture, sf::Vector2u(2, 2), font, 350));
					enough = true;
				}

				break;
			case 2:
				printTextCbyC("Easy right?\nHow about this?", n);
				enough = false;
				break;
			case 3:
				
				if (!enough) {
					enemy1List.push_back(new Enemy2(&Enemy2Texture, sf::Vector2u(2, 2), font, 350));
					enemy1List.push_back(new Enemy2(&Enemy2Texture, sf::Vector2u(2, 2), font, 350));
					enough = true;
				}
				break;
			case 4:
				printTextCbyC("Not bad...", n);
				break;
			
			case 5:
				actualMessage.setCharacterSize(70);
				actualMessage.setFillColor(sf::Color::Red);
				printTextCbyC("HOW ABOUT THIS?", n);
				enough = false;
				break;
			case 6:
				if (!enough)
				{
					for (size_t i = 0; i < 100; i++)
					{
						enemy1List.push_back(new Enemy1(&Enemy1Texture, sf::Vector2u(2, 2), font));
					}
					enough = true;
				}
				break;
			case 7:
				for (size_t i = 0;i< enemy1List.size(); i++)
				{
					delete enemy1List.at(i);
					enemy1List.erase(enemy1List.begin() + i);
				}
				printTextCbyC("HEHE...\nDon't worry, just kidding.\nYou can either dodge or kill them.", n);
				enough = false;
				break;

			case 8:
				printTextCbyC("<--WATCH OUT FOR THINGS LIKE THIS", n);
				break;
			case 9:
				
				if (!enough) {
					enemy3List.push_back(new Enemy3(&Enemy3Texture, sf::Vector2u(1, 1), Bashy.body.getPosition().x, Bashy.body.getPosition().y, 1250.0f));
					enough = true;
				}
				break;
			
			case 10:
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
				GameOvertext.setString("Stage Done, GL & HF Bashy");
				GameOvertext.setFont(font);
				GameOvertext.setFillColor(sf::Color::Green);
				GameOvertext.setPosition(sf::Vector2f((window.getSize().x / 2)-200, window.getSize().y / (2 + 1) * 1));

				GameOvertext2.setCharacterSize(30);
				GameOvertext2.setString("Move next ('Enter'), restart('r'), quit('q')?");
				GameOvertext2.setFont(font);
				GameOvertext2.setFillColor(sf::Color::Green);
				GameOvertext2.setPosition(sf::Vector2f((window.getSize().x / 2)-200, window.getSize().y / (2 + 1) * 2));
				
			}
		}

		//system("CLS");
		//std::cout << teszttime;
		deltaTime = clock.restart().asSeconds();

		sf::Event event;

		while (window.pollEvent(event))
		{
			if (!GameOver && !endStage) {
				if (event.type == sf::Event::TextEntered)
				{
					playerInput += event.text.unicode;
					playerText.setString(playerInput);
					/*if (scene == 1 && (enemy1List.at(0)->getText().getString()) == playerText.getString()) {

						delete enemy1List.at(0);
						enemy1List.erase(enemy1List.begin());
						scene++;
					}*/
					checkEnemyList(event, Bashy);
					
					//std::cout << "size: " << enemy1List.size();
					//checkEnemyList(event, Bashy);


				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) { //ENTER NYOM�S LEGYEN VAGY CSAK SIMA P�TY�G�S

					/*for (int i = 0; i < enemy1List.size(); i++) {
						if (enemy1List.at(i)->getText().getString() == playerInput) {
							enemy1List.at(i)->state = Dying;
							enemy1List.at(i)->Update(deltaTime, Bashy.GetBody(), GameOver);
							//std::cout << "size: " << enemy1List.size();
						}
					}*/
					//scene++;
					playerInput = "";
					playerText.setString(playerInput);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) { //backspace m�k�dtet�se

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
				if (enemy1List.at(i)->GetCollider().CheckCollision(Bashy.GetCollider()) && GameOver != true) {
					if (scene == 6) { //Utols� scene innen m�r meg�ll�tjuk.
						scene++;
					}
					else if (scene != 7) {
						GameOver = true;
					}
				}
				
				break;

			case Dying:

				enemy1List.at(i)->state = Dead;

				break;
			case Dead:

				delete enemy1List.at(i);
				enemy1List.erase(enemy1List.begin() + i);
				hitnumber++;
				break;
			}
		}
		for (size_t i = 0; i < enemy3List.size(); i++)
		{
			enemy3List.at(i)->Update(deltaTime,font);
			if (enemy3List.at(i)->GetCollider().CheckCollision(Bashy.GetCollider()) && GameOver != true) {
				
					GameOver = true;
				
			}
		}
		for (int i = 0; i < enemy3List.size(); i++) { //RAK�TA delete
			if (enemy3List.at(i)->state == Stop) {
				delete enemy3List.at(i);
				enemy3List.erase(enemy3List.begin() + i);
				scene++; //Scene l�ptet�s
			}
		}

		if (hitnumber != 0) { //ha scene 1 , �s az 1db unit dead akk k�vi scene
			if (scene == 1 && hitnumber == 1) {
				scene++;
				hitnumber = 0;
			}
			if (scene == 3 && hitnumber == 2) {
				//ha scene 3 �s az az 2 db unit dead akk next
				scene++;
				hitnumber = 0;
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

		// screen t�rl�se mielott kirajzolom az �jakat
		window.clear();
		
		// kirajzol�s
		Bashy.Draw(window);
		//gg.Draw(window);
		if (enemy3List.size() > 0) { //RAK�TA DRAW
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
		// window megjelenit�s
		window.display();
	}


	return 0;
}
