#pragma once
#include <iostream>
#include <vector>

class Life
{
private:
	int rows;
	int cols;
	int refresh_time;
	int startLifeCount;
	int size;
	std::vector<std::vector<char>> gameBoard;

public:
	Life(int rows, int cols, int refresh_time, int startLifeCount);
	void beginLife();
	void printBoard();
	void updateBoard();
	void evolve();
	int getNeighboursCount(int row, int col);
};