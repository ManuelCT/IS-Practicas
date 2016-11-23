#include "stdafx.h"
#include <vector>
#include "worldValues.h"
#include "worldManagement.h"
#include "enemyManagement.h"
#include "bulletManagement.h"
#include "colisions.h"
#include "keyControl.h"
#include "playerValues.h"
#include "weatherManagement.h"
#include "scoreManagement.h"

class World gameWorld(WORLD_WIDTH);

int main() {
	//VARIABLES DECLARATION
	char cKey = 't';
	unsigned int iPlayerPos;
	srand(static_cast<unsigned int>(time(NULL)));


	while (playAgain(cKey)) {
	//WORLD INITIALITATION
	initScore();
	iPlayerPos = PLAYER_INITIAL_POSITION;
	gameWorld.changePositionSymbol(iPlayerPos, PLAYER_SYMBOL);

		//GAME LOOP
		while (checkPlayerAlive(iPlayerPos)) {

			gameWorld.changePositionSymbol(iPlayerPos, PLAYER_SYMBOL);

			updateWeather();

			checkEnemiesKilled();

			if ((rand() % 100) <= 5) {
				newEnemy();
			}


			if (_kbhit()) {
				cKey = _getch();
				keyControl(cKey, iPlayerPos);
			}

			system("cls");
			gameWorld.printWorld(getScore());

			updateBullets();

			updateEnemies();

			Sleep(50);
		}

		system("cls");
		printf("GAME OVER\n\n\n\nScore: %d\n\n\nEnter x to exit\n", getScore());

		scanf_s("%c", &cKey);

		gameWorld.resetWorld(WORLD_WIDTH);
	}

	return 0;
}

