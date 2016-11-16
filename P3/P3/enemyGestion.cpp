#include "stdafx.h"
#include "enemyGestion.h"
#include "worldValues.h"

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

//Sets enemy positions or resets its position and adds 1 to score
void setEnemyPosition(unsigned int & iEnemyPos, unsigned int & iEnemyDirection, char * cWorld) {
	if (iEnemyDirection == 1) {
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