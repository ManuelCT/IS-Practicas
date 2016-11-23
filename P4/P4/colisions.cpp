#include "stdafx.h"
#include "colisions.h"


//Checks if a bullets has hit the enemy
void checkEnemiesKilled() {
	std::vector<Enemy>::iterator enemiesIterator = gameWorld.getEnemies();
	std::vector<Enemy>::iterator enemiesEnd = gameWorld.getLastEnemy();
	std::vector<Bullet>::iterator bulletsIterator = gameWorld.getBullets();
	std::vector<Bullet>::iterator bulletsEnd = gameWorld.getLastBullet();

	if (gameWorld.sizeBullets() != 0 && gameWorld.sizeEnemies() != 0) {
		for (; bulletsIterator != bulletsEnd; bulletsIterator++) {
			for (; enemiesIterator != enemiesEnd; enemiesIterator++) {
				if (abs(static_cast<int>(enemiesIterator->iPosition - bulletsIterator->iPosition)) <= 1) {
					gameWorld.destroyBullet(bulletsIterator);
					gameWorld.destroyEnemy(enemiesIterator);
					addScore(1);
				}
			}
		}
	}
}

//Checks if the player is still alive
bool checkPlayerAlive(unsigned int & iPlayerPos) {
	std::vector<Enemy>::iterator enemiesIterator = gameWorld.getEnemies();
	std::vector<Enemy>::iterator enemiesEnd = gameWorld.getLastEnemy();

	if (gameWorld.sizeEnemies() != 0) {
		for (; enemiesIterator != enemiesEnd; enemiesIterator++) {
			if (abs(static_cast<int>(enemiesIterator->iPosition - iPlayerPos)) <= 1) {
				return false;
			}
		}
	}
	return true;
}