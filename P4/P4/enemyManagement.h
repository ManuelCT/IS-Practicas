#ifndef __ENEMYMANAGEMENT_H__
#define __ENEMYMANAGEMENT_H__

#define ENEMY_SYMBOL 'X'

void resetEnemy(unsigned int & iEnemyPos, unsigned int & iEnemyDirection, char * cWorld);
void setEnemyPosition(unsigned int & iEnemyPos, unsigned int & iEnemyDirection, char * cWorld);

#endif // !__ENEMYMANAGEMENT_H__
