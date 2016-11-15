#include "stdafx.h"

#define WORLD_WIDTH  30
#define PLAYER_INITIAL_POSITION WORLD_WIDTH/2
#define WORLD_SYMBOL '_'
#define PLAYER_SYMBOL  '*'
#define BULLET_SYMBOL '-'
#define ENEMY_SYMBOL 'X'
#define KEY_LEFT_MOVE 'a'
#define KEY_RIGHT_MOVE 'd'
#define KEY_LEFT_SHOT 'q'
#define KEY_RIGHT_SHOT 'e'

void resetBullet(int & iBulletPos, unsigned int & iBulletDirection, char * cWorld) {
	cWorld[iBulletPos] = WORLD_SYMBOL;
	iBulletDirection = 0;
	iBulletPos = -1;
}

void resetEnemy(unsigned int & iEnemyPos, unsigned int & iEnemyDirection, char * cWorld) {
	cWorld[iEnemyPos] = WORLD_SYMBOL;
	if (rand() % 2 == 1) {
		iEnemyPos = 0;
		iEnemyDirection = 2;
	}
	else {
		iEnemyPos = WORLD_WIDTH - 1;
		iEnemyDirection = 1;
	}
}

void setBulletPosition(int & iBulletPos, unsigned int & iBulletDirection, char * cWorld) {
	if (iBulletDirection == 1) {
		--iBulletPos;
		cWorld[iBulletPos] = BULLET_SYMBOL;
		cWorld[iBulletPos + 1] = WORLD_SYMBOL;
	}
	else if (iBulletDirection == 2) {
		++iBulletPos;
		cWorld[iBulletPos] = BULLET_SYMBOL;
		cWorld[iBulletPos - 1] = WORLD_SYMBOL;
	}
}

//Sets enemy positions or resets its position and adds 1 to score
void setEnemyPosition(unsigned int & iEnemyPos, unsigned int & iEnemyDirection, int & iBulletPos, unsigned int & iBulletDirection, unsigned int & iScore, char * cWorld) {
	if (abs(static_cast<int>(iEnemyPos-iBulletPos)) <= 1) {
		resetBullet(iBulletPos, iBulletDirection, cWorld);
		resetEnemy(iEnemyPos, iEnemyDirection, cWorld);
		++iScore;
	}
	else if (iEnemyDirection == 1) {
		if (iEnemyPos != 0) {
			--iEnemyPos;
			cWorld[iEnemyPos] = ENEMY_SYMBOL;
			cWorld[iEnemyPos + 1] = WORLD_SYMBOL;
		}
		else
			resetEnemy(iEnemyPos, iEnemyDirection, cWorld);
	}
	else {
		if (iEnemyPos != (WORLD_WIDTH - 1)) {
			++iEnemyPos;
			cWorld[iEnemyPos] = ENEMY_SYMBOL;
			cWorld[iEnemyPos - 1] = WORLD_SYMBOL;
		}
		else
			resetEnemy(iEnemyPos, iEnemyDirection, cWorld);
	}
}

//Checks if the player is still alive
bool checkPlayer(unsigned int & iPlayerPos, unsigned int & iEnemyPos) {
	if (abs(static_cast<int>(iEnemyPos - iPlayerPos)) <= 1) {
		return false;
	}
	return true;
}

int main() {
	//VARIABLES DECLARATION
	char * cWorld = new char [WORLD_WIDTH + 1];
	char cKey;
	unsigned int iPlayerPos = PLAYER_INITIAL_POSITION;
	int iBulletPos;
	unsigned int iScore = 0;
	unsigned int iEnemyPos = 0;
	unsigned int iBulletDirection = 0; //0 -> No Bullet. 1 -> Left Direction Bullet. 2 -> Right Direction Bullet.
	unsigned int iEnemyDirection = 0; //0 -> No Enemy. 1 -> Left Direction Enemy. 2 -> Right Direction Enemy.
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
		if (_kbhit()) {
			cKey = _getch();
			if (cKey == KEY_LEFT_MOVE) {
				if (iPlayerPos != 0) {
					--iPlayerPos;
					cWorld[iPlayerPos] = PLAYER_SYMBOL;
					cWorld[iPlayerPos + 1] = WORLD_SYMBOL;
				}
			}
			else if (cKey == KEY_RIGHT_MOVE) {
				if (iPlayerPos != WORLD_WIDTH) {
					++iPlayerPos;
					cWorld[iPlayerPos] = PLAYER_SYMBOL;
					cWorld[iPlayerPos - 1] = WORLD_SYMBOL;
				}
			}
			else if (iBulletDirection == 0) {
				if (cKey == KEY_LEFT_SHOT) {
					if (iPlayerPos != 0) {
						iBulletPos = iPlayerPos - 1;
						iBulletDirection = 1;
					}
				}
				else if (cKey == KEY_RIGHT_SHOT) {
					if (iPlayerPos != (WORLD_WIDTH - 1)) {
						iBulletPos = iPlayerPos + 1;
						iBulletDirection = 2;
					}
				}
			}
		}

		setBulletPosition(iBulletPos, iBulletDirection, cWorld);

		if (iEnemyDirection != 0) {
			setEnemyPosition(iEnemyPos, iEnemyDirection, iBulletPos, iBulletDirection, iScore, cWorld);
		}

		if (iBulletPos == 0 || iBulletPos == (WORLD_WIDTH - 1)) {
			resetBullet(iBulletPos, iBulletDirection, cWorld);
		}

		system("cls");
		printf("Score: %d\n\n\n\n%s", iScore, cWorld);

		Sleep(200);
	}
	system("cls");
	printf("GAME OVER\n\n\n\nScore: %d", iScore);
	delete[] cWorld;
	getchar();
	return 0;
}

