#include "stdafx.h"
#include "weatherManagement.h"

//Stocks all existing drops
static std::vector<Drop> vDrops;

static Drop nextStep(Drop sDrop) {
	sDrop.iAge = sDrop.iAge + 1;
	sDrop.iPosition = sDrop.iPosition;
	return sDrop;
}

//Adds a new Drop in a random position
static void newDrop() {
		unsigned int iDropPos = rand() % (WORLD_WIDTH);
		Drop stDrop;
		stDrop.iAge = 0;
		stDrop.iPosition = iDropPos;
		vDrops.push_back(stDrop);
}

//Creates a new drops if conditions are accomplished and update all existing drops
void updateWeather() {
	std::vector<Drop>::iterator dropsIterator;
	std::vector<Drop> vNewDrops;

	if ((rand() % 5) < 1) {
		newDrop();
	}

	for (dropsIterator = vDrops.begin(); dropsIterator != vDrops.end(); dropsIterator++) {
		if (dropsIterator->iAge == 0) {
			gameWorld.changePositionSymbol(dropsIterator->iPosition, HIGH_DROP_SYMBOL);
			vNewDrops.push_back(nextStep(*dropsIterator));
		}
		else if (dropsIterator->iAge == 1) {
			gameWorld.changePositionSymbol(dropsIterator->iPosition, MEDIUM_DROP_SYMBOL);
			vNewDrops.push_back(nextStep(*dropsIterator));
		}
		else if (dropsIterator->iAge == 2) {
			gameWorld.changePositionSymbol(dropsIterator->iPosition, LOW_DROP_SYMBOL);
			vNewDrops.push_back(nextStep(*dropsIterator));
		}
		else {
			gameWorld.changePositionSymbol(dropsIterator->iPosition, WORLD_SYMBOL);
		}
	}

	vDrops.clear();
	vDrops = vNewDrops;
	vNewDrops.clear();
}