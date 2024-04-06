#include <iostream>
#include "Life.h"

int main() {
	srand(time(NULL));
	const int ROWS = 20;
	const int COLS = 20;
	const int REFRESH_TIME = 1;
	const int START_LIFE_COUNT = 30;

	Life life = Life(ROWS, COLS, REFRESH_TIME, START_LIFE_COUNT);
	life.beginLife();

	return 0;
}