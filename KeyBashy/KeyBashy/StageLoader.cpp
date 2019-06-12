#include "StageLoader.h"

StageLoader::StageLoader() {
	


}

void StageLoader::loadStage(int stageNum, sf::RenderWindow& window, BashyTerminal& Bashy) {

	while (stageNum != 0) {
		switch (stageNum) {

		case 0:
			
			break;

		case 1:
			
			stageNum = tutorStage.Start(window,Bashy);
			
			break;
		case 2:
			stageNum = mainstage.Start(window, Bashy);
			break;
		case 3:
			stageNum = stagemenu.Start(window);
			break;
		}
	}
}