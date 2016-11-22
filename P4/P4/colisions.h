#ifndef __COLISIONS_H__
#define __COLISIONS_H__

#include "worldManagement.h"
#include "enemyManagement.h"
#include "bulletManagement.h"
#include "worldValues.h"
#include "scoreManagement.h"

void checkEnemiesKilled();
bool checkPlayerAlive(unsigned int & iPlayerPos);

#endif // !__COLISIONS_H__
