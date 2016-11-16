#ifndef __COLISIONS_H__
#define __COLISIONS_H__

void checkEnemy(unsigned int & iEnemyPos, unsigned int & iEnemyDirection, int & iBulletPos, unsigned int & iBulletDirection, unsigned int & iScore, char * cWorld);
bool checkPlayer(unsigned int & iPlayerPos, unsigned int & iEnemyPos);

#endif // !__COLISIONS_H__
