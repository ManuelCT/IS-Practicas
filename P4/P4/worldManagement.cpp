#include "stdafx.h"
#include "worldManagement.h"

World::World(unsigned int iWorldWidth) {
	cWorld = new char[WORLD_WIDTH + 1];
}

World::~World() {
	delete[] cWorld;
}

void World::changePositionSymbol(unsigned int iPosition, char cSymbol) {
	cWorld[iPosition] = cSymbol;
	vBullets.clear();
}