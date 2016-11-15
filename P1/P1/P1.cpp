// P1.cpp : Defines the entry point for the console application.
//

//_kbhit()
//_getch()

#include "stdafx.h"

#define WORLD_WIDTH  52
#define PLAYER_INITIAL_POSITION 25
#define WORLD_SYMBOL '_'
#define PLAYER_SYMBOL  '*'
#define BULLET_SYMBOL '-'

int main () {
	//VARS DECLARATION
	char cWorld[WORLD_WIDTH];
	char cKey;
	unsigned int iPlayerPos = PLAYER_INITIAL_POSITION;
	unsigned int iBulletPos;
	unsigned int iBulletDirection = 0;

	//WORLD INITIALITATION
	for	(unsigned int i = 0; i < WORLD_WIDTH; i++) {
		cWorld[i] = WORLD_SYMBOL;
	}
	cWorld[WORLD_WIDTH - 1] = '\0';
	cWorld[iPlayerPos] = PLAYER_SYMBOL;
	printf("\n\n\n\n%s", cWorld);

	//GAME LOOP
	while (true) {
		if (_kbhit()) {
			cKey = _getch();

			if (cKey == 'a') {
				if (iPlayerPos != 0) {
					--iPlayerPos;
					cWorld[iPlayerPos] = PLAYER_SYMBOL;
					cWorld[iPlayerPos + 1] = WORLD_SYMBOL;
				}
			}

			else if (cKey == 'd') {
				if (iPlayerPos != (WORLD_WIDTH - 2)) {
					++iPlayerPos;
					cWorld[iPlayerPos] = PLAYER_SYMBOL;
					cWorld[iPlayerPos - 1] = WORLD_SYMBOL;
				}
			}

			else if (iBulletDirection == 0) {
				if (cKey == 'q') {
					if (iPlayerPos != 0) {
						iBulletPos = iPlayerPos - 1;
						iBulletDirection = 1;
					}
				}

				else if (cKey == 'e') {
					if (iPlayerPos != (WORLD_WIDTH - 2)) {
						iBulletPos = iPlayerPos + 1;
						iBulletDirection = 2;
					}
				}
			}
		}

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

		if (iBulletPos == 0 || iBulletPos == (WORLD_WIDTH - 2)) {
			cWorld[iBulletPos] = WORLD_SYMBOL;
			iBulletDirection = 0;
			iBulletPos = WORLD_WIDTH / 2;
		}

		system("cls");
		printf("\n\n\n\n%s", cWorld);
		Sleep(200);
	}

    return 0;
}

