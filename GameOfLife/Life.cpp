#include "Life.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <algorithm>

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

// clear screen and then print
void Life::printBoard() {
	std::this_thread::sleep_for(std::chrono::seconds(this->refresh_time));
	std::system("cls");

	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->cols; j++) {
			std::cout << " " << this->gameBoard[i][j];
		}
		std::cout << std::endl;
	}
}


int Life::getNeighboursCount(int row, int col) {
	int neighbourCount = 0;

	bool top_edge = (row == 0);
	bool bottom_edge = (row == this->rows-1);
	bool left_edge = (col == 0);
	bool right_edge = (col == this->cols - 1);

	int check_row_min = row - 1;
	int check_row_max = row + 1;
	int check_col_min = col - 1;
	int check_col_max = col + 1;

	if (top_edge) {
		check_row_min = row;
	}
	if (bottom_edge) {
		check_row_max = row;
	}
	if (left_edge) {
		check_col_min = col;
	}
	if (right_edge) {
		check_col_max = col;
	}

	for (int i = check_row_min; i <= check_row_max; i++) {
		for (int j = check_col_min; j <= check_col_max; j++) {
			if (this->gameBoard[i][j] == 'O') {
				neighbourCount++;
			}
		}
	}	

	return neighbourCount -1; // to exclude the cell itself
}

void Life::updateBoard() {
	std::vector<std::vector<char>> updatedBoard = this->gameBoard;

	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->cols; j++) {
			if (this->getNeighboursCount(i, j) < 1) {
					updatedBoard[i][j] = 'X';
			}
			else {
				updatedBoard[i][j] = 'O';
			}
		}
		std::cout << std::endl;
	}

	this->gameBoard = updatedBoard;
}