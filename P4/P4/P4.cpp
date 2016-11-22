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
	char cKey;
	unsigned int iPlayerPos = PLAYER_INITIAL_POSITION;
	srand(static_cast<unsigned int>(time(NULL)));

	//WORLD INITIALITATION
	initScore();
	gameWorld.changePositionSymbol(iPlayerPos, PLAYER_SYMBOL);
	gameWorld.printWorld(getScore());

	//GAME LOOP
	while (checkPlayerAlive(iPlayerPos)) {

		gameWorld.changePositionSymbol(iPlayerPos, PLAYER_SYMBOL);

		updateWeather();

		updateBullets();
		
		updateEnemies();

		checkEnemiesKilled();

		if ((rand() % 5) < 2) {
			newEnemy();
			printf("Nuevo ENEMIGO\n");
		}
			

		if (_kbhit()) {
			cKey = _getch();
			keyControl(cKey, iPlayerPos);
		}

		system("cls");
		gameWorld.printWorld(getScore());

		Sleep(50);
	}

	system("cls");
	printf("GAME OVER\n\n\n\nScore: %d\n\n\n", getScore());

	getchar();
	return 0;
}

