#include "stdafx.h"
#include "enemyManagement.h"

void newEnemy() {
	Enemy sEnemy;

	unsigned int iEnemyDirection = rand() % 2;
	sEnemy.iDirection = iEnemyDirection + 1;

	if(sEnemy.iDirection == 1)
		sEnemy.iPosition = WORLD_WIDTH - 1;
	else
		sEnemy.iPosition = 0;

	gameWorld.addEnemy(sEnemy);
}

void updateEnemies() {
	
	if (gameWorld.sizeEnemies() != 0) {
		std::vector<Enemy>::iterator enemiesIterator = gameWorld.getEnemies();
		std::vector<Enemy>::iterator enemiesEnd = gameWorld.getLastEnemy();
		std::vector<Enemy> vNewEnemies;
		Enemy sEnemy;

		for (; enemiesIterator != enemiesEnd; enemiesIterator++) {
			if (enemiesIterator->destroy == true) {
				gameWorld.changePositionSymbol(enemiesIterator->iPosition, WORLD_SYMBOL);
				if (enemiesIterator->iDirection == 1) {
					gameWorld.changePositionSymbol(enemiesIterator->iPosition + 1, WORLD_SYMBOL);
				}
				else {
					gameWorld.changePositionSymbol(enemiesIterator->iPosition - 1, WORLD_SYMBOL);
				}
			}
			else if (enemiesIterator->iDirection == 1) {
				sEnemy.iPosition = enemiesIterator->iPosition - 1;
				sEnemy.iDirection = 1;
				vNewEnemies.push_back(sEnemy);
				gameWorld.changePositionSymbol(enemiesIterator->iPosition, ENEMY_SYMBOL);
				if (enemiesIterator->iPosition != (WORLD_WIDTH - 1))
					gameWorld.changePositionSymbol(enemiesIterator->iPosition + 1, WORLD_SYMBOL);
			}
			else {
				sEnemy.iPosition = enemiesIterator->iPosition + 1;
				sEnemy.iDirection = 2;
				vNewEnemies.push_back(sEnemy);
				gameWorld.changePositionSymbol(enemiesIterator->iPosition, ENEMY_SYMBOL);
				if (enemiesIterator->iPosition != 0)
					gameWorld.changePositionSymbol(enemiesIterator->iPosition - 1, WORLD_SYMBOL);
			}
		}

		gameWorld.setEnemies(vNewEnemies);
		vNewEnemies.clear();
	}
}