#include "stdafx.h"
#include "enemyGestion.h"
#include "bulletGestion.h"
#include "worldValues.h"

//Checks if a bullets has hit the enemy
void checkEnemy(unsigned int & iEnemyPos, unsigned int & iEnemyDirection, int & iBulletPos, unsigned int & iBulletDirection, unsigned int & iScore, char * cWorld) {
	if (abs(static_cast<int>(iEnemyPos - iBulletPos)) <= 1) {
		resetBullet(iBulletPos, iBulletDirection, cWorld);
		resetEnemy(iEnemyPos, iEnemyDirection, cWorld);
		++iScore;
	}
}

//Checks if the player is still alive
bool checkPlayer(unsigned int & iPlayerPos, unsigned int & iEnemyPos) {
	if (abs(static_cast<int>(iEnemyPos - iPlayerPos)) <= 1) {
		return false;
	}
	return true;
}