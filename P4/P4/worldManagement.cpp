#include "stdafx.h"
#include "worldManagement.h"

World::World(unsigned int iWorldWidth) {
	cWorld = new char[iWorldWidth + 1];

	for (unsigned int i = 0; i < iWorldWidth; ++i) {
		changePositionSymbol(i, WORLD_SYMBOL);
	}
	cWorld[iWorldWidth] = '\0';
}

World::~World() {
	delete[] cWorld;
	vBullets.clear();
	vEnemies.clear();
}

void World::changePositionSymbol(unsigned int iPosition, char cSymbol) {
		cWorld[iPosition] = cSymbol;
}

void World::initWorld(unsigned int iWorldWidth) {
	cWorld = new char[iWorldWidth + 1];

	for (unsigned int i = 0; i < iWorldWidth; ++i) {
		changePositionSymbol(i, WORLD_SYMBOL);
	}
	cWorld[iWorldWidth] = '\0';
}

void World::resetWorld(unsigned int iWorldWidth) {
	for (unsigned int i = 0; i < iWorldWidth; ++i) {
		changePositionSymbol(i, WORLD_SYMBOL);
	}
	cWorld[iWorldWidth] = '\0';
	vBullets.clear();
	vEnemies.clear();
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

std::vector<Bullet>::iterator World::getBullets() {
	return vBullets.begin();
}

std::vector<Enemy>::iterator World::getEnemies() {
	return vEnemies.begin();
}

std::vector<Bullet>::iterator World::getLastBullet() {
	return vBullets.end();
}

std::vector<Enemy>::iterator World::getLastEnemy() {
	return vEnemies.end();
}

void World::clearBullets() {
	vBullets.clear();
}

void World::clearEnemies() {
	vEnemies.clear();
}

void World::destroyBullet(std::vector<Bullet>::iterator bulletsIterator) {
	bulletsIterator->destroy = true;
}

void World::destroyEnemy(std::vector<Enemy>::iterator enemiesIterator) {
	enemiesIterator->destroy = true;
}

size_t World::sizeBullets() {
	return vBullets.size();
}

size_t World::sizeEnemies() {
	return vEnemies.size();
}