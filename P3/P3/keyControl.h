#ifndef __KEYCONTROL_H__
#define __KEYCONTROL_H__

#include"worldValues.h"

#define KEY_LEFT_MOVE 'a'
#define KEY_RIGHT_MOVE 'd'
#define KEY_LEFT_SHOT 'q'
#define KEY_RIGHT_SHOT 'e'

void keyControl(char cKey, unsigned int & iPlayerPos, int & iBulletPos, unsigned int & iBulletDirection, char * cWorld);


#endif // !__KEYCONTROL_H__