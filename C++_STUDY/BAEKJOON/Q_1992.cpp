#include <iostream>
#include <string>
using namespace std;

#define ONE 1
#define ZERO 0

int grid[65][65];
int num_of_one = 0, num_of_zero = 0;

void CUT(int row, int col, int length) {
	int number = grid[row][col];
	bool BREAK = false;

	for (int i = row; (i < row + length) & !BREAK; i++) {
		for (int j = col; (j < col + length) & !BREAK; j++) {
			int number2 = grid[i][j];
			if (number != number2)
				BREAK = true;
		}
	}

	if (BREAK) {
		cout << '(';
		int new_length = length / 2;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				CUT(row + i * new_length, col + j * new_length, new_length);
		cout << ')';
	}
	else {
		if (number == ONE)
			cout << 1;
		else if (number == ZERO)
			cout << 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	string line;
	for (int i = 1; i <= N; i++) {
		cin >> line;
		for (int j = 1; j <= N; j++)
			grid[i][j] = (line[j - 1] - '0');
	}

	CUT(1, 1, N);

	return 0;
}