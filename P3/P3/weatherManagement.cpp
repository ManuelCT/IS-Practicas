#include "stdafx.h"
#include "weatherManagement.h"

//Stocks all existing drops
static std::vector<Drop> vDrops;

//Adds a new Drop in a random position
static void newDrop() {
		unsigned int iDropPos = rand() % (WORLD_WIDTH);
		struct Drop stDrop;
		stDrop.iAge = 0;
		stDrop.iPosition = iDropPos;
		vDrops.push_back(stDrop);
}

//Creates a new drops if conditions are accomplished and update all existing drops
void updateWeather(char * cWorld) {
	std::vector<Drop>::iterator dropsIterator;
	std::vector<Drop> vNewDrops;

	if ((rand() % 10) < 2) {
		newDrop();
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