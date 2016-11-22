#include "stdafx.h"
#include "colisions.h"


//Checks if a bullets has hit the enemy
void checkEnemiesKilled() {
	std::vector<Enemy> pEnemies = gameWorld.getEnemies();
	std::vector<Bullet> pBullets = gameWorld.getBullets();
	std::vector<Bullet>::iterator bulletsIterator = pBullets.begin();
	std::vector<Enemy>::iterator enemiesIterator = pEnemies.begin();

	if (pEnemies.size() && pBullets.size() != 0) {
		for (; bulletsIterator != pBullets.end(); bulletsIterator++) {
			for (; enemiesIterator != pEnemies.end(); enemiesIterator++) {
				if (abs(static_cast<int>(enemiesIterator->iPosition - bulletsIterator->iPosition)) <= 1) {
					enemiesIterator->destroy = true;
					bulletsIterator->destroy = true;
					addScore(1);
				}
			}
		}
	}
}

//Checks if the player is still alive
bool checkPlayerAlive(unsigned int & iPlayerPos) {
	std::vector<Enemy> pEnemies = gameWorld.getEnemies();
	std::vector<Enemy>::iterator enemiesIterator = pEnemies.begin();

	if (gameWorld.getEnemies().size() != 0) {
		for (; enemiesIterator != pEnemies.end(); enemiesIterator++) {
			if (abs(static_cast<int>(enemiesIterator->iPosition - iPlayerPos)) <= 1) {
				return false;
			}
		}
	}
	return true;
}