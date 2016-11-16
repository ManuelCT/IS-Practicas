#include "stdafx.h"
#include "weatherGestion.h"

void updateWeather(std::vector<struct Drop> * vDrops, unsigned int & iPlayerPos, unsigned int & iEnemyPos, int & iBulletPos, char * cWorld) {
	unsigned int iDropPos = rand() % (WORLD_WIDTH + 1);
	struct Drop stDrop;
	struct Drop stCheckDrops;

	//if (iDropPos != iPlayerPos && iDropPos != iEnemyPos && iDropPos != iBulletPos) {
		stDrop.iAge = 0;
		stDrop.iPosition = iDropPos;
		vDrops->push_back(stDrop);
	//}

	for (std::vector<struct Drop>::iterator dropsIterator = vDrops->begin(); dropsIterator != vDrops->end(); ++dropsIterator) {
		stCheckDrops = *dropsIterator;
		if (stCheckDrops.iAge == 0) {
			cWorld[stDrop.iPosition] = HIGH_DROP_SYMBOL;
			//++stCheckDrops.iAge;
		}
		else if (stCheckDrops.iAge == 1) {
			cWorld[stDrop.iPosition] = MEDIUM_DROP_SYMBOL;
			//++stCheckDrops.iAge;
		}
		else if (stCheckDrops.iAge == 1) {
			cWorld[stDrop.iPosition] = LOW_DROP_SYMBOL;
			//++stCheckDrops.iAge;
		}
		else {
			cWorld[stDrop.iPosition] = WORLD_SYMBOL;
			vDrops->erase(dropsIterator);
		}
	}

}
