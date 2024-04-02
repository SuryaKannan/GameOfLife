#include <iostream>
#include <vector>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <cstdlib>

std::vector<std::vector<char>> createGameBoard(int rows, int cols);
void printGameBoard(std::vector<std::vector<char>> gameBoard, int rows, int cols);
void beginGame(std::vector<std::vector<char>> gameBoard, int rows, int cols, int refresh_time);

int main() {
	int rows = 50;
	int cols = 80;
	int inital_row = rand() % rows;
	int initial_col = rand() % cols;
	int refresh_time = 0.5; // seconds between print game screen

	std::vector<std::vector<char>> gameBoard = createGameBoard(rows, cols);
	beginGame(gameBoard, rows, cols, refresh_time);
}

void beginGame(std::vector<std::vector<char>> gameBoard, int rows, int cols, int refresh_time) {
	while (true) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::system("cls");
		printGameBoard(gameBoard, rows, cols);
	}
}

std::vector<std::vector<char>> createGameBoard(int rows, int cols) {

	std::vector<std::vector<char>> gameBoard;
	gameBoard.assign(rows, std::vector < char >(cols, 'O'));

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

