#pragma once
#include <SFML\Graphics.hpp>
#include "StageTest.h"

class StageLoader
{

	StageLoader(int stageNum);

public:

	int loadStage(int stageNum, sf::RenderWindow& window);

private:

	TestStage* tStage;
	int stageNum;

};

