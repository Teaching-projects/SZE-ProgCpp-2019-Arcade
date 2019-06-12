#pragma once
#include <SFML\Graphics.hpp>
#include "TutorialStage.h"
#include "StageTest.h"
#include "MainStage.h"
#include "StageMenu.h"

class StageLoader
{
public:
	StageLoader();
	void loadStage(int stageNum, sf::RenderWindow& window, BashyTerminal& Bashy);

private:
	//sf::Texture terminalTexture;
	
	TutorialStage tutorStage;
	MainStage mainstage;
	StageMenu stagemenu;
	//TestStage tStage;
	
};

