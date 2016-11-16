#include "stdafx.h"
#include <vector>
#include "worldValues.h"
#include "enemyGestion.h"
#include "bulletGestion.h"
#include "colisions.h"
#include "keyControl.h"
#include "playerValues.h"
#include "weatherGestion.h"

int main() {
	//VARIABLES DECLARATION
	char * cWorld = new char[WORLD_WIDTH + 1];
	char cKey;
	unsigned int iPlayerPos = PLAYER_INITIAL_POSITION;
	int iBulletPos;
	unsigned int iScore = 0;
	unsigned int iEnemyPos = 0;
	unsigned int iBulletDirection = 0; //0 -> No Bullet. 1 -> Left Direction Bullet. 2 -> Right Direction Bullet.
	unsigned int iEnemyDirection = 0; //0 -> No Enemy. 1 -> Left Direction Enemy. 2 -> Right Direction Enemy.
	std::vector<struct Drop> vDrops;
	srand(static_cast<unsigned int>(time(NULL)));

	//WORLD INITIALITATION
	for (unsigned int i = 0; i < WORLD_WIDTH; ++i) {
		printf("%d\n", i);
		cWorld[i] = WORLD_SYMBOL;
	}

	resetEnemy(iEnemyPos, iEnemyDirection, cWorld);

	cWorld[WORLD_WIDTH] = '\0';
	cWorld[iPlayerPos] = PLAYER_SYMBOL;
	printf("Score: %d\n\n\n\n%s", iScore, cWorld);

	//GAME LOOP
	while (checkPlayer(iPlayerPos, iEnemyPos)) {

		cWorld[iPlayerPos] = PLAYER_SYMBOL;

		updateWeather(&vDrops, iPlayerPos, iEnemyPos, iBulletPos, cWorld);

		checkEnemy(iEnemyPos, iEnemyDirection, iBulletPos, iBulletDirection, iScore, cWorld);

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
		printf("Score: %d\n\n\n\n%s", iScore, cWorld);

		Sleep(200);
	}
	system("cls");
	printf("GAME OVER\n\n\n\nScore: %d\n\n\n", iScore);
	delete[] cWorld;
	cWorld = NULL;
	getchar();
	return 0;
}

