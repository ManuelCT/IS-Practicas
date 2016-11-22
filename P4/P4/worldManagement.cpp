#include "stdafx.h"
#include "worldManagement.h"

World::World(unsigned int iWorldWidth) {
	cWorld = new char[WORLD_WIDTH + 1];

	for (unsigned int i = 0; i < WORLD_WIDTH; ++i) {
		changePositionSymbol(i, WORLD_SYMBOL);
	}
	cWorld[WORLD_WIDTH] = '\0';
}

World::~World() {
	delete[] cWorld;
	vBullets.clear();
	vEnemies.clear();
}

void World::changePositionSymbol(unsigned int iPosition, char cSymbol) {
	if (iPosition <= 0 && iPosition >= (WORLD_WIDTH - 1))
		cWorld[iPosition] = cSymbol;
}

void World::initWorld(unsigned int iWorldWidth) {
	cWorld = new char[WORLD_WIDTH + 1];

	for (unsigned int i = 0; i < WORLD_WIDTH; ++i) {
		changePositionSymbol(i, WORLD_SYMBOL);
	}
	cWorld[WORLD_WIDTH] = '\0';
}

void World::printWorld(int iScore) {
	printf("Score: %d\n\n\n\n%s", iScore, cWorld);
}

void World::addBullet(Bullet sBullet) {
	vBullets.push_back(sBullet);
}

void World::addEnemy(Enemy sEnemy) {
	vEnemies.push_back(sEnemy);
}

void World::setBullets(std::vector<Bullet> newBullets) {
	clearBullets();
	vBullets = newBullets;
}

void World::setEnemies(std::vector<Enemy> newEnemies) {
	clearEnemies();
	vEnemies = newEnemies;
}

std::vector<Bullet> World::getBullets() {
	return vBullets;
}

std::vector<Enemy> World::getEnemies() {
	return vEnemies;
}

void World::clearBullets() {
	vBullets.clear();
}

void World::clearEnemies() {
	vEnemies.clear();
}