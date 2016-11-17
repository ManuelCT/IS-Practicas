#ifndef __BULLETMANAGEMENT_H__
#define __BULLETMANAGEMENT_H__

#define BULLET_SYMBOL '-'

#include <vector>
#include "worldValues.h"

struct Bullet {
	unsigned int iPosition;
	unsigned int iDirection; //0 -> No Bullet. 1 -> Left Direction Bullet. 2 -> Right Direction Bullet.
};

void addBullet(struct Bullet);
void updateBullets(char * cWorld);
#endif // !__BULLETMANAGEMENT_H__
