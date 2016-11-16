#ifndef __WEATHERGESTION_H__
#define __WEATHERGESTION_H__

#include <vector>
#include "worldValues.h"

#define HIGH_DROP_SYMBOL  '\''
#define MEDIUM_DROP_SYMBOL  '|'
#define LOW_DROP_SYMBOL  '.'

struct Drop {
	unsigned int iPosition;
	unsigned int iAge;
};

void updateWeather(std::vector<struct Drop> * vDrops, unsigned int & iPlayerPos, unsigned int & iEnemyPos, int & iBulletPos, char * cWorld);

#endif // !__WEATHERGESTION_H__