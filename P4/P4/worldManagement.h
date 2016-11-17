#ifndef __WORLDMANAGEMENT_H__
#define __WORLDMANAGEMENT_H__

#include <vector>
#include "worldValues.h"
#include "bulletManagement.h"

class World {
private:
	char * cWorld;
	static std::vector<Bullet> vBullets;

public:
	World(unsigned int iWorldWidth);
	~World();
	void changePositionSymbol(unsigned int iPosition, char cSymbol);
};

extern class World;

#endif // !__WORLDMANAGEMENT_H__
