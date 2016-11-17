#ifndef __BULLETMANAGEMENT_H__
#define __BULLETMANAGEMENT_H__

#define BULLET_SYMBOL '-'

#include "worldValues.h"

void resetBullet(int & iBulletPos, unsigned int & iBulletDirection, char * cWorld);
void setBulletPosition(int & iBulletPos, unsigned int & iBulletDirection, char * cWorld);

#endif // !__BULLETMANAGEMENT_H__
