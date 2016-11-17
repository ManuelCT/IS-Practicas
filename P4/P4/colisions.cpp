#include "stdafx.h"
#include "colisions.h"


//Checks if a bullets has hit the enemy
void checkEnemy(unsigned int & iEnemyPos, unsigned int & iEnemyDirection, int & iBulletPos, unsigned int & iBulletDirection, char * cWorld) {
	if (abs(static_cast<int>(iEnemyPos - iBulletPos)) <= 1) {
		resetBullet(iBulletPos, iBulletDirection, cWorld);
		resetEnemy(iEnemyPos, iEnemyDirection, cWorld);
		addScore(1);
	}
}

//Checks if the player is still alive
bool checkPlayer(unsigned int & iPlayerPos, unsigned int & iEnemyPos) {
	if (abs(static_cast<int>(iEnemyPos - iPlayerPos)) <= 1) {
		return false;
	}
	return true;
}