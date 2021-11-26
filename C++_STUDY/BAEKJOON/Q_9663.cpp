#include <iostream>
#include <iomanip>
#include <string>

/*
	할 것 : mark O가 제대로 지우지 못하는것같음.
	N = 4일때 (0,0), (1,3), (2, 1) 과 같이 Q를 놓는 경우를 내 코드에서는 찾을 수가 없음
*/

int res = 0;
int N;
std::string** chess;

void find(int row, int col, int numOfQueen);
void mark(int row, int col, std::string mark, int numOfQueen);
void view();	// debug

int main() {
	std::cin >> N;

	chess = new std::string* [N];
	for (int i = 0; i < N; i++) {
		chess[i] = new std::string[N];
		for (int j = 0; j < N; j++) {
			chess[i][j] = 'O';
		}
	}

	find(0,0,0);
	std::cout << res;

	for (int i = 0; i < N; i++) {
		delete[] chess[i];
	}

	delete[] chess;

	return 0;
}

void find(int row, int col, int numOfQueen) {
	std::cout << "test::" << row << " " << col << '\n';
	view();
	
	if (row == N || col == N) {
		if (numOfQueen == N)	res++;
		return;
	}

	std::string& currLoc = chess[row][col];

	if (numOfQueen == N) {
		res++;
		mark(row, col, "O", numOfQueen);
		currLoc = "O";
		numOfQueen--;

		find(row + 1, col, numOfQueen);
		find(row, col + 1, numOfQueen);
		find(row + 1, col + 1, numOfQueen);
		return;
	}

	if (currLoc == "O") {
		
		mark(row, col, "X", numOfQueen);
		currLoc = 'Q';
		numOfQueen++;


		find(row + 1, col + 1, numOfQueen);

		mark(row, col, "O", numOfQueen);
		currLoc = 'O';
		numOfQueen--;

	}
	find(row + 1, col, numOfQueen);
	find(row, col + 1, numOfQueen);
	find(row + 1, col + 1, numOfQueen);
}

void mark(int row, int col, std::string mark, int numOfQueen) {
	std::string marking = mark + std::to_string(numOfQueen);
	std::string rev_marking = mark == "O" ? "X" + std::to_string(numOfQueen) : "O";

	// for CROSS
	for (int indx = 0; indx < N; indx++) {
		if (chess[row][indx] == rev_marking)
			chess[row][indx] = marking;
		if (chess[indx][col] == rev_marking)
		chess[indx][col] = marking;
	}

	// for Diagonal
	int c_up = col;
	int c_down = col;
	for (int r = row; r < N; r++) {
		if (chess[r][c_up] == rev_marking)
			chess[r][c_up] = marking;
		if (chess[r][c_down] == rev_marking)
			chess[r][c_down] = marking;
		c_up = c_up == N - 1 ? c_up : c_up + 1;
		c_down = c_down == 0 ? c_down : c_down - 1;
	}

	c_up = col;
	c_down = col;
	for (int r = row; r >= 0; r--) {
		if (chess[r][c_up] == rev_marking)
			chess[r][c_up] = marking;
		if (chess[r][c_down] == rev_marking)
			chess[r][c_down] = marking;
		c_up = c_up == N - 1 ? c_up : c_up + 1;
		c_down = c_down == 0 ? c_down : c_down - 1;
	}
}

void view() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cout << chess[i][j] << std::setw(4);
		}
		std::cout << '\n';
	}
}