#include "StageLoader.h"

StageLoader::StageLoader(int stageNum) {

	this->stageNum = stageNum;
	
}

int StageLoader::loadStage(int stageNum, sf::RenderWindow& window) {

	switch (stageNum) {
	
	case 0:
		if (tStage != NULL) {
			delete tStage;
			tStage = new TestStage();
		}
		tStage = new TestStage();
		tStage->Start(window);
		break;
	}

	return 1;
}