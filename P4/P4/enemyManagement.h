#ifndef __ENEMYMANAGEMENT_H__
#define __ENEMYMANAGEMENT_H__

#define ENEMY_SYMBOL 'X'

#include <vector>
#include "worldManagement.h"
#include "worldValues.h"

struct Enemy {
	unsigned int iPosition;
	unsigned int iDirection; //0 -> No Bullet. 1 -> Left Direction Bullet. 2 -> Right Direction Bullet.
	bool destroy = false;
};

void newEnemy();
void updateEnemies();

#endif // !__ENEMYMANAGEMENT_H__
