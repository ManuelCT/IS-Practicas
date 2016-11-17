#include "stdafx.h"
#include "bulletManagement.h"

void addBullet(Bullet sBullet) {
	cWorld.vBullets.push_back(sBullet);
}

void updateBullets(char * cWorld) {
	std::vector<Bullet>::iterator bulletsIterator;
	std::vector<Bullet> vNewBullets;

	for (bulletsIterator = cWorld.vBullets.begin(); bulletsIterator != cWorld.vBullets.end(); bulletsIterator++) {
		if (bulletsIterator->iPosition == 0 || bulletsIterator->iPosition == (WORLD_WIDTH - 1)) {
			cWorld[bulletsIterator->iPosition] = WORLD_SYMBOL;
		}
		else if (bulletsIterator->iDirection == 1) {
			cWorld[bulletsIterator->iPosition] = BULLET_SYMBOL;
			cWorld[bulletsIterator->iPosition + 1] = WORLD_SYMBOL;
			vNewBullets.push_back({ bulletsIterator->iPosition - 1, bulletsIterator->iDirection });
		}
		else if (bulletsIterator->iDirection == 2) {
			cWorld[bulletsIterator->iPosition] = BULLET_SYMBOL;
			cWorld[bulletsIterator->iPosition + 1] = WORLD_SYMBOL;
			vNewBullets.push_back({ bulletsIterator->iPosition + 1, bulletsIterator->iDirection });
		}
	}

	vBullets.clear();
	vBullets = vNewBullets;
	vNewBullets.clear();
}