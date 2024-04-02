#include <iostream>
#include <vector>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <cstdlib>

void printGameBoard(std::vector<std::vector<char>> gameBoard, int rows, int cols);
std::vector<std::vector<char>> createGameBoard(int rows, int cols, int initial_row, int initial_col);
void beginGame(std::vector<std::vector<char>> gameBoard, int rows, int cols, int refresh_time);

int main() {
	srand(time(NULL));
	int rows = 50;
	int cols = 80;
	int inital_row = rand() % rows;
	int initial_col = rand() % cols;
	int refresh_time = 1; 

	std::vector<std::vector<char>> gameBoard = createGameBoard(rows, cols, inital_row,initial_col);
	beginGame(gameBoard, rows, cols, refresh_time);
}

void beginGame(std::vector<std::vector<char>> gameBoard, int rows, int cols, int refresh_time) {
	while (true) {
		std::this_thread::sleep_for(std::chrono::seconds(refresh_time));
		std::system("cls");
		printGameBoard(gameBoard, rows, cols);
	}
}

std::vector<std::vector<char>> createGameBoard(int rows, int cols, int initial_row, int initial_col) {

	std::vector<std::vector<char>> gameBoard;
	gameBoard.assign(rows, std::vector < char >(cols, 'x'));

	gameBoard[initial_row][initial_col] = 'O';

	return gameBoard;
}

void printGameBoard(std::vector<std::vector<char>> gameBoard, int rows, int cols) {

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << gameBoard[i][j] << " ";
		}
		std::cout << std::endl;
	}
}