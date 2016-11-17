#ifndef __COLISIONS_H__
#define __COLISIONS_H__

#include "enemyManagement.h"
#include "bulletManagement.h"
#include "worldValues.h"
#include "scoreManagement.h"

void checkEnemy(unsigned int & iEnemyPos, unsigned int & iEnemyDirection, int & iBulletPos, unsigned int & iBulletDirection, char * cWorld);
bool checkPlayer(unsigned int & iPlayerPos, unsigned int & iEnemyPos);

#endif // !__COLISIONS_H__
