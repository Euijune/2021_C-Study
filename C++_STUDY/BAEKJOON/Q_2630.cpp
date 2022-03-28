#include <iostream>
using namespace std;

#define BLUE 1
#define WHITE 0

int grid[129][129];
int num_of_blue = 0, num_of_white = 0;

void CUT(int row, int col, int length) {
	int color = grid[row][col];
	bool BREAK = false;

	for (int i = row; (i < row + length) & !BREAK; i++) {
		for (int j = col; (j < col + length) & !BREAK; j++) {
			int color2 = grid[i][j];
			if (color != color2)
				BREAK = true;
		}
	}

	if (BREAK) {
		CUT(row, col, length / 2);		                        // I
		CUT(row, col + length / 2, length / 2);		            // II
		CUT(row + length / 2, col, length / 2);		            // III
		CUT(row + length / 2, col + length / 2, length / 2);	// IV
	}
	else {
		if (color == BLUE)
			num_of_blue++;
		else
			num_of_white++;
	}
}

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> grid[i][j];

	CUT(1, 1, N);
	cout << num_of_white << '\n' << num_of_blue;

	return 0;
}