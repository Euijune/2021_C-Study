#include <iostream>
using namespace std;

int N;
int ans;
int grid[14];

bool canPutQueen(int curr) {
	int curr_row = grid[curr];
	int curr_col = curr;

	for (int c = 0; c < curr; c++) {
		int c_row = grid[c];
		int c_col = c;
		if (c_row == curr_row || abs(curr_row - c_row) == abs(curr_col - c_col))
			return false;
	}

	return true;
}

void chess(int curr, int cnt) {

	if (cnt == N) {
		ans++;
		return;
	}

	for (int i = 0; i < N; i++) {
		grid[curr] = i;
		if (canPutQueen(curr))
			chess(curr + 1, cnt + 1);
	}	
}

int main() {
	cin >> N;

	chess(0, 0);
	cout << ans;

	return 0;
}