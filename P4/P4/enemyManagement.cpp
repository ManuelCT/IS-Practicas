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
	
	if (gameWorld.getEnemies().size() != 0) {
		std::vector<Enemy> pEnemies = gameWorld.getEnemies();
		std::vector<Enemy>::iterator enemiesIterator = pEnemies.begin();
		std::vector<Enemy> vNewEnemies;
		Enemy sEnemy;

		for (; enemiesIterator != pEnemies.end(); enemiesIterator++) {
			//printf("%d %d\n", enemiesIterator->iPosition, enemiesIterator->destroy);
			if (enemiesIterator->iPosition == 0 || enemiesIterator->iPosition == (WORLD_WIDTH - 1) && enemiesIterator->destroy == true) {
				gameWorld.changePositionSymbol(enemiesIterator->iPosition, WORLD_SYMBOL);
				if (enemiesIterator->iDirection == 1) {
					gameWorld.changePositionSymbol(enemiesIterator->iPosition + 1, WORLD_SYMBOL);
				}
				else {
					gameWorld.changePositionSymbol(enemiesIterator->iPosition - 1, WORLD_SYMBOL);
				}
			}
			else if (enemiesIterator->iDirection == 1) {
				gameWorld.changePositionSymbol(enemiesIterator->iPosition, ENEMY_SYMBOL);
				gameWorld.changePositionSymbol(enemiesIterator->iPosition + 1, WORLD_SYMBOL);
				sEnemy.iPosition = enemiesIterator->iPosition - 1;
				sEnemy.iDirection = 1;
				vNewEnemies.push_back(sEnemy);
			}
			else if (enemiesIterator->iDirection == 2) {
				gameWorld.changePositionSymbol(enemiesIterator->iPosition, ENEMY_SYMBOL);
				gameWorld.changePositionSymbol(enemiesIterator->iPosition - 1, WORLD_SYMBOL);
				sEnemy.iPosition = enemiesIterator->iPosition + 1;
				sEnemy.iDirection = 2;
				vNewEnemies.push_back(sEnemy);
			}
		}

		gameWorld.setEnemies(vNewEnemies);
		vNewEnemies.clear();
		pEnemies.clear();
	}
}