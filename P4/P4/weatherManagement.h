#ifndef __WEATHERMANAGEMENT_H__
#define __WEATHERMANAGEMENT_H__

#include <vector>
#include "worldValues.h"

#define HIGH_DROP_SYMBOL  '\''
#define MEDIUM_DROP_SYMBOL  '|'
#define LOW_DROP_SYMBOL  '.'

struct Drop {
	unsigned int iPosition;
	unsigned int iAge;
};

static void newDrop();
void updateWeather(char * cWorld);

#endif // !__WEATHERMANAGEMENT_H__