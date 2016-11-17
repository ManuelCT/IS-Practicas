#include "stdafx.h"
#include "scoreManagement.h"

static int score;

void initScore() {
	score = 0;
}

void addScore(int points) {
	score += points;
}

int getScore() {
	return score;
}
