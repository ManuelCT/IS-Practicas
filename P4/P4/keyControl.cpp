#include "stdafx.h"
#include "keyControl.h"

void keyControl(char cKey, unsigned int & iPlayerPos) {
	Bullet sBullet;
	if (cKey == KEY_LEFT_MOVE) {
		if (iPlayerPos != 0) {
			--iPlayerPos;
			gameWorld.changePositionSymbol(iPlayerPos, PLAYER_SYMBOL);
			gameWorld.changePositionSymbol(iPlayerPos + 1, WORLD_SYMBOL);
		}
	}
	else if (cKey == KEY_RIGHT_MOVE) {
		if (iPlayerPos != WORLD_WIDTH) {
			++iPlayerPos;
			gameWorld.changePositionSymbol(iPlayerPos, PLAYER_SYMBOL);
			gameWorld.changePositionSymbol(iPlayerPos - 1, WORLD_SYMBOL);
		}
	}
	if (cKey == KEY_LEFT_SHOT) {
		if (iPlayerPos != 0) {
			sBullet.iPosition = iPlayerPos - 1;
			sBullet.iDirection = 1;
			newBullet(sBullet);
		}
	}
	else if (cKey == KEY_RIGHT_SHOT) {
		if (iPlayerPos != (WORLD_WIDTH - 1)) {
			sBullet.iPosition = iPlayerPos + 1;
			sBullet.iDirection = 2;
			newBullet(sBullet);
		}
	}
}