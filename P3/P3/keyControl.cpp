#include "stdafx.h"
#include "keyControl.h"
#include "worldValues.h"
#include "playerValues.h"

void keyControl(char cKey, unsigned int & iPlayerPos, int & iBulletPos, unsigned int & iBulletDirection, char * cWorld) {
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
	else if (iBulletDirection == 0) {
		if (cKey == KEY_LEFT_SHOT) {
			if (iPlayerPos != 0) {
				iBulletPos = iPlayerPos - 1;
				iBulletDirection = 1;
			}
		}
		else if (cKey == KEY_RIGHT_SHOT) {
			if (iPlayerPos != (WORLD_WIDTH - 1)) {
				iBulletPos = iPlayerPos + 1;
				iBulletDirection = 2;
			}
		}
	}
}