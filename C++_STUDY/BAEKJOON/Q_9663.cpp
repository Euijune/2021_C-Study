#include <iostream>

int res = 0;
int N;
char** chess;

void find(int row, int col);

int main() {
	std::cin >> N;

	chess = new char* [N];
	for (int i = 0; i < N; i++) {
		chess[i] = new char[N];
		for (int j = 0; j < N; j++) {
			chess[i][j] = 'O';
		}
	}

	find(0,0);

	for (int i = 0; i < N; i++) {
		delete chess[i];
	}

	delete[] chess;

	return 0;
}

void find(int row, int col) {
	char currLoc = chess[row][col];

	if (currLoc == 'O') {
		currLoc = 'Q';

		// for CROSS
		for (int indx = 0; indx < N; indx++) {
			chess[row][indx] = indx == col ? chess[row][indx] : 'X';
			chess[indx][col] = indx == row ? chess[indx][col] : 'X';
		}

		// for Diagonal
		
	}
}