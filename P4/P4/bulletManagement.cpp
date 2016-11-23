#include "stdafx.h"
#include "bulletManagement.h"

void newBullet(Bullet sBullet) {
	gameWorld.addBullet(sBullet);
}

void updateBullets() {

	if (gameWorld.sizeBullets() != 0) {
		std::vector<Bullet>::iterator bulletsIterator = gameWorld.getBullets();
		std::vector<Bullet>::iterator bulletsEnd = gameWorld.getLastBullet();
		std::vector<Bullet> vNewbullets;
		Bullet sBullet;

		for (; bulletsIterator != bulletsEnd; bulletsIterator++) {
			if (bulletsIterator->destroy == true || bulletsIterator->iPosition == 0 || bulletsIterator->iPosition == (WORLD_WIDTH - 1)) {
				gameWorld.changePositionSymbol(bulletsIterator->iPosition, WORLD_SYMBOL);
				if (bulletsIterator->iDirection == 1) {
					gameWorld.changePositionSymbol(bulletsIterator->iPosition + 1, WORLD_SYMBOL);
				}
				else {
					gameWorld.changePositionSymbol(bulletsIterator->iPosition - 1, WORLD_SYMBOL);
				}
					
			}
			else if (bulletsIterator->iDirection == 1) {
				gameWorld.changePositionSymbol(bulletsIterator->iPosition, BULLET_SYMBOL);
				gameWorld.changePositionSymbol(bulletsIterator->iPosition + 1, WORLD_SYMBOL);
				sBullet.iPosition = bulletsIterator->iPosition - 1;
				sBullet.iDirection = 1;
				vNewbullets.push_back(sBullet);
			}
			else if (bulletsIterator->iDirection == 2) {
				gameWorld.changePositionSymbol(bulletsIterator->iPosition, BULLET_SYMBOL);
				gameWorld.changePositionSymbol(bulletsIterator->iPosition - 1, WORLD_SYMBOL);
				sBullet.iPosition = bulletsIterator->iPosition + 1;
				sBullet.iDirection = 2;
				vNewbullets.push_back(sBullet);
			}
		}

		gameWorld.setBullets(vNewbullets);
		vNewbullets.clear();
	}

}