#include <iostream>
using namespace std;

#define BLUE 1
#define WHITE 0

int grid[129][129];
int num_of_blue = 0, num_of_white = 0;

void CUT(int L_row, int L_col, int R_row, int R_col, int length) {
	//cout << L_row << " " << L_col << " " << R_row << " " << R_col << endl;
	int color = grid[L_row][L_col];
	bool BREAK = false;

	for (int i = L_row; (i <= R_row) & !BREAK; i++) {
		for (int j = L_col; (j <= R_col) & !BREAK; j++) {
			int color2 = grid[i][j];
			if (color != color2)
				BREAK = true;
		}
	}

	if (BREAK) {
		CUT(L_row, L_col, R_row - length/ 2, R_col - length / 2, length / 2);		// I
		CUT(L_row, L_col + length / 2, R_row  - length / 2, R_col, length / 2);		// II
		CUT(L_row + length / 2, L_col, R_row, R_col - length / 2 , length / 2);		// III
		CUT(L_row + length / 2, L_col + length / 2, R_row, R_col, length / 2);		// IV
	}
	else {
		if (color == BLUE) {
			//cout << "blue" << endl;
			num_of_blue++;
		}
		else {
			//cout << "white" << endl;
			num_of_white++;
		}
	}
}

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> grid[i][j];

	CUT(1, 1, N, N, N);
	cout << num_of_white << '\n' << num_of_blue;

	return 0;
}