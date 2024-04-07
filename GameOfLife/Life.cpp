#include "Life.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <algorithm>

/*
	RULES OF LIFE

	Any live cell with fewer than two live neighbors dies, as if by underpopulation.
	Any live cell with two or three live neighbors lives on to the next generation.
	Any live cell with more than three live neighbors dies, as if by overpopulation.
	Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
*/

// ANSI Escape Codes for colored output
const std::string ALIVE = "\033[32m"; // green
const std::string DEAD = "\033[31m"; // red

Life::Life(int rows, int cols, int refresh_time, int startLifeCount)
	: rows(rows), cols(cols), refresh_time(refresh_time), startLifeCount(startLifeCount), gameBoard(rows, std::vector<char>(cols, 'X')) {
	this->size = rows * cols;

}

// start game only if starting life count is less than game board size
void Life::beginLife() {
	if (this->startLifeCount > this->size) {
		std::cout << "Start life count is greater than the size of the board! Re-enter starting population" << std::endl;
		return;
	}
	else {
		for (int i = 0; i < this->startLifeCount; i++) {
			this->gameBoard[rand() % this->rows][rand() % this->cols] = 'O';
		}
		this->evolve();
	}

};

void Life::evolve() {
	while (true) {
		this->printBoard();
		this->updateBoard();
	}

}

void Life::printBoard() {
	std::this_thread::sleep_for(std::chrono::milliseconds(this->refresh_time));
	std::system("cls");

	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->cols; j++) {
			if (this->gameBoard[i][j] == 'O') {
				std::cout << ALIVE << " " << this->gameBoard[i][j];
			}
			else {
				std::cout << DEAD << " " << this->gameBoard[i][j];
			}
		}
		std::cout << std::endl;
	}

}

int Life::getNeighboursCount(int cell_row, int cell_col) {
	int neighbourCount = 0;
	int check_row_min = std::max(0, cell_row - 1);
	int check_row_max = std::min(this->rows - 1, cell_row + 1);
	int check_col_min = std::max(0, cell_col - 1);
	int check_col_max = std::min(this->cols - 1, cell_col + 1);

	for (int i = check_row_min; i <= check_row_max; i++) {
		for (int j = check_col_min; j <= check_col_max; j++) {
			if (i == cell_row && j == cell_col) {
				continue; // Skip the current cell
			}
			if (this->gameBoard[i][j] == 'O') {
				neighbourCount++;
			}
		}
	}

	return neighbourCount;
}

void Life::updateBoard() {
	std::vector<std::vector<char>> updatedBoard = this->gameBoard;
	int neighbourCount = 0;

	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->cols; j++) {
			neighbourCount = this->getNeighboursCount(i, j);

			if (neighbourCount <= 1) { 
				updatedBoard[i][j] = 'X';
			}
			else if ((neighbourCount == 2 || neighbourCount == 3) && this->gameBoard[i][j] == 'O') { 
				continue;
			}
			else if (neighbourCount == 3 && this->gameBoard[i][j] == 'X') {
				updatedBoard[i][j] = 'O';
			}
			else {
				updatedBoard[i][j] = 'X';
			}
		}
		std::cout << std::endl;
	}

	this->gameBoard = updatedBoard;
}