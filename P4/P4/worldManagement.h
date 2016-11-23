#ifndef __WORLDMANAGEMENT_H__
#define __WORLDMANAGEMENT_H__

#include <vector>
#include "worldValues.h"
#include "bulletManagement.h"
#include "enemyManagement.h"

struct Bullet;
struct Enemy;

class World {
private:
	char * cWorld;
	std::vector<Bullet> vBullets;
	std::vector<Enemy> vEnemies;

	void clearBullets();
	void clearEnemies();

public:
	World(unsigned int iWorldWidth);
	~World();
	void initWorld(unsigned int iWorldWidth);
	void resetWorld(unsigned int iWorldWidth);
	void changePositionSymbol(unsigned int iPosition, char cSymbol);
	void printWorld(int iScore);
	void addBullet(Bullet sBullet);
	void addEnemy(Enemy sEnemy);
	void setBullets(std::vector<Bullet> newBullets);
	void setEnemies(std::vector<Enemy> newEnemies);
	std::vector<Bullet>::iterator getBullets();
	std::vector<Enemy>::iterator getEnemies();
	std::vector<Bullet>::iterator getLastBullet();
	std::vector<Enemy>::iterator getLastEnemy();
	void destroyBullet(std::vector<Bullet>::iterator bulletsIterator);
	void destroyEnemy(std::vector<Enemy>::iterator enemiesIterator);
	size_t sizeBullets();
	size_t sizeEnemies();
	
};

extern class World gameWorld;

#endif // !__WORLDMANAGEMENT_H__
