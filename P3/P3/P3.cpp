#include "stdafx.h"
#include <vector>
#include "worldValues.h"
#include "enemyManagement.h"
#include "bulletManagement.h"
#include "colisions.h"
#include "keyControl.h"
#include "playerValues.h"
#include "weatherManagement.h"
#include "scoreManagement.h"

int main() {
	//VARIABLES DECLARATION
	char * cWorld = new char[WORLD_WIDTH + 1];
	char cKey;
	unsigned int iPlayerPos = PLAYER_INITIAL_POSITION;
	int iBulletPos;
	unsigned int iEnemyPos = 0;
	unsigned int iBulletDirection = 0; //0 -> No Bullet. 1 -> Left Direction Bullet. 2 -> Right Direction Bullet.
	unsigned int iEnemyDirection = 0; //0 -> No Enemy. 1 -> Left Direction Enemy. 2 -> Right Direction Enemy.
	srand(static_cast<unsigned int>(time(NULL)));

	//WORLD INITIALITATION
	for (unsigned int i = 0; i < WORLD_WIDTH; ++i) {
		printf("%d\n", i);
		cWorld[i] = WORLD_SYMBOL;
	}
	initScore();
	resetEnemy(iEnemyPos, iEnemyDirection, cWorld);
	cWorld[WORLD_WIDTH] = '\0';
	cWorld[iPlayerPos] = PLAYER_SYMBOL;
	printf("Score: %d\n\n\n\n%s", getScore(), cWorld);

	//GAME LOOP
	while (checkPlayer(iPlayerPos, iEnemyPos)) {

		cWorld[iPlayerPos] = PLAYER_SYMBOL;

		updateWeather(cWorld);

		checkEnemy(iEnemyPos, iEnemyDirection, iBulletPos, iBulletDirection, cWorld);

		setBulletPosition(iBulletPos, iBulletDirection, cWorld);

		if (_kbhit()) {
			cKey = _getch();
			keyControl(cKey, iPlayerPos, iBulletPos, iBulletDirection, cWorld);
		}

		if (iEnemyDirection != 0) {
			setEnemyPosition(iEnemyPos, iEnemyDirection, cWorld);
		}

		if (iBulletPos == 0 || iBulletPos == (WORLD_WIDTH - 1)) {
			resetBullet(iBulletPos, iBulletDirection, cWorld);
		}

		system("cls");
		printf("Score: %d\n\n\n\n%s", getScore(), cWorld);

		Sleep(50);
	}
	system("cls");
	printf("GAME OVER\n\n\n\nScore: %d\n\n\n", getScore());
	delete[] cWorld;
	cWorld = NULL;
	getchar();
	return 0;
}

