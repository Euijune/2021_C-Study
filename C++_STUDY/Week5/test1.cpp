#include <iostream>
using namespace std;

#define R first
#define C second
typedef pair<int, int> pii;

void init(int n, pii curr) {
	for (int r = 0; r < n; r++)
		for (int c = 0; c < n; c++)
			grid[r][c] = -1;
	grid [curr.R][curr.C] = 0;
}

int DFS(int count, pii target) {
	if (grid[target.R][target.C] != -1)
		 return grid[target.R][target.C];

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