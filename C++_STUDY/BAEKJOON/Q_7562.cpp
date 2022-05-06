#include <iostream>
using namespace std;

#define R first
#define C second
typedef pair<int, int> pii;

int N;
int grid[300][300];

void init(int n, pii curr);
void DFS(int count, pii target);
void move(int r, int c);
bool inRange(int r, int c);

int main() {
	int T;
	cin >> T;

	pii curr, target;

	while (T--) {
		cin >> N;
		cin >> curr.R >> curr.C;
		init(N, curr);

		cin >> target.R >> target.C;

		DFS(0, target);
		cout << grid[target.R][target.C] << endl;
	}

	return 0;
}

void init(int n, pii curr) {
	for (int r = 0; r < n; r++)
		for (int c = 0; c < n; c++)
			grid[r][c] = -1;
	grid[curr.R][curr.C] = 0;
}

void DFS(int count, pii target) {
	if (grid[target.R][target.C] != -1)
		return;

	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			if (grid[r][c] == count)
				move(r, c);

	DFS(count + 1, target);
}

void move(int r, int c) {
	int dr[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
	int dc[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

	for (int dir = 0; dir < 8; dir++) {
		int nr = r + dr[dir];
		int nc = c + dc[dir];

		if (inRange(nr, nc) && grid[nr][nc] == -1)
			grid[nr][nc] = grid[r][c] + 1;
	}
}

bool inRange(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < N;
}