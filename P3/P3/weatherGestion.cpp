#include "stdafx.h"
#include "weatherGestion.h"

void updateWeather(std::vector<struct Drop> & vDrops, unsigned int & iPlayerPos, unsigned int & iEnemyPos, int & iBulletPos, char * cWorld) {
	std::vector<struct Drop>::iterator dropsIterator;
	std::vector<struct Drop> vNewDrops;

	if ((rand() % 10) < 2) {
		unsigned int iDropPos = rand() % (WORLD_WIDTH);
		struct Drop stDrop;
		stDrop.iAge = 0;
		stDrop.iPosition = iDropPos;
		vDrops.push_back(stDrop);
	}

	for (dropsIterator = vDrops.begin(); dropsIterator != vDrops.end(); dropsIterator++) {
		if (dropsIterator->iAge == 0) {
			cWorld[dropsIterator->iPosition] = HIGH_DROP_SYMBOL;
			vNewDrops.push_back({ dropsIterator->iPosition, dropsIterator->iAge + 1});
		}
		else if (dropsIterator->iAge == 1) {
			cWorld[dropsIterator->iPosition] = MEDIUM_DROP_SYMBOL;
			vNewDrops.push_back({ dropsIterator->iPosition, dropsIterator->iAge + 1 });
		}
		else if (dropsIterator->iAge == 2) {
			cWorld[dropsIterator->iPosition] = LOW_DROP_SYMBOL;
			vNewDrops.push_back({ dropsIterator->iPosition, dropsIterator->iAge + 1 });
		}
		else {
			cWorld[dropsIterator->iPosition] = WORLD_SYMBOL;
		}
	}

	vDrops.clear();
	vDrops = vNewDrops;

	vNewDrops.clear();
}