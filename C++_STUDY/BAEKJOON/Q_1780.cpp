#include <iostream>
using namespace std;

#define ONE 1
#define ZERO 0
#define NEG_ONE -1

int grid[2188][2188];
int num_of_one = 0, num_of_zero = 0, num_of_neg_one = 0;

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
		int new_length = length / 3;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				CUT(row + i * new_length, col + j * new_length, new_length);
	}
	else {
		if (number == ONE)
			num_of_one++;
		else if (number == ZERO)
			num_of_zero++;
		else
			num_of_neg_one++;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> grid[i][j];

	CUT(1, 1, N);
	cout << num_of_neg_one << '\n' << num_of_zero << '\n' << num_of_one;

	return 0;
}