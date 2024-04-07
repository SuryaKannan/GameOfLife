#include <iostream>
#include "Life.h"

int main() {
	srand(time(NULL));
	const int ROWS = 50;
	const int COLS = 50;
	const int REFRESH_TIME = 500; // milliseconds
	const int START_LIFE_COUNT = 200;

	Life life = Life(ROWS, COLS, REFRESH_TIME, START_LIFE_COUNT);
	life.beginLife();

	return 0;
}