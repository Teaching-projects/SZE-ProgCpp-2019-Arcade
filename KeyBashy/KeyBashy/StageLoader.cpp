#include "StageLoader.h"

StageLoader::StageLoader() {
	
}

int StageLoader::loadStage(int stageNum, sf::RenderWindow& window) {

	while (stageNum != 0) {
		switch (stageNum) {

		case 0:
			return 0;
			break;

		case 1:
			stageNum = tStage.Start(window);
			break;
		}
	}
}