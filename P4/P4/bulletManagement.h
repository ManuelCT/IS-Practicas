#ifndef __BULLETMANAGEMENT_H__
#define __BULLETMANAGEMENT_H__

#define BULLET_SYMBOL '-'

#include <vector>
#include "worldManagement.h"
#include "worldValues.h"

struct Bullet {
	unsigned int iPosition;
	unsigned int iDirection; //0 -> No Bullet. 1 -> Left Direction Bullet. 2 -> Right Direction Bullet.
	bool destroy = false;
};

void newBullet(Bullet sBullet);
void updateBullets();
#endif // !__BULLETMANAGEMENT_H__
