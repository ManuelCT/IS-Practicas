#include "stdafx.h"
#include "bulletManagement.h"

void resetBullet(int & iBulletPos, unsigned int & iBulletDirection, char * cWorld) {
	cWorld[iBulletPos] = WORLD_SYMBOL;
	iBulletDirection = 0;
	iBulletPos = -1;
}

void setBulletPosition(int & iBulletPos, unsigned int & iBulletDirection, char * cWorld) {
	if (iBulletDirection == 1) {
		--iBulletPos;
		cWorld[iBulletPos] = BULLET_SYMBOL;
		cWorld[iBulletPos + 1] = WORLD_SYMBOL;
	}
	else if (iBulletDirection == 2) {
		++iBulletPos;
		cWorld[iBulletPos] = BULLET_SYMBOL;
		cWorld[iBulletPos - 1] = WORLD_SYMBOL;
	}
}