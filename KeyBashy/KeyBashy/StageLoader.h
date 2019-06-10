#pragma once
#include <SFML\Graphics.hpp>
#include "StageTest.h"

class StageLoader
{
public:
	StageLoader();
	int loadStage(int stageNum, sf::RenderWindow& window);

private:

	int stageNum;
	TestStage tStage;

};

