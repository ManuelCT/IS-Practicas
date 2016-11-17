#include "stdafx.h"
#include "keyControl.h"

void keyControl(char cKey, unsigned int & iPlayerPos, char * cWorld) {
	if (cKey == KEY_LEFT_MOVE) {
		if (iPlayerPos != 0) {
			--iPlayerPos;
			cWorld[iPlayerPos] = PLAYER_SYMBOL;
			cWorld[iPlayerPos + 1] = WORLD_SYMBOL;
		}
	}
	else if (cKey == KEY_RIGHT_MOVE) {
		if (iPlayerPos != WORLD_WIDTH) {
			++iPlayerPos;
			cWorld[iPlayerPos] = PLAYER_SYMBOL;
			cWorld[iPlayerPos - 1] = WORLD_SYMBOL;
		}
	}
	if (cKey == KEY_LEFT_SHOT) {
		if (iPlayerPos != 0) {
			addBullet({ iPlayerPos - 1, 1 });
		}
	}
	else if (cKey == KEY_RIGHT_SHOT) {
		if (iPlayerPos != (WORLD_WIDTH - 1)) {
			addBullet({ iPlayerPos + 1, 2 });
		}
	}
}