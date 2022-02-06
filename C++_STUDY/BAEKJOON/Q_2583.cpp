#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;

int M, N;
int grid[100][100];
bool visit[100][100];

bool inRange(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < M;
}

bool canGo(int x, int y) {
	return !visit[y][x] && inRange(x, y) && grid[y][x] == 0;
}

void DFS(int x, int y, int& area) {
	visit[y][x] = true;
	int dxs[4] = { 0, 0, 1, -1 };
	int dys[4] = { 1, -1, 0, 0 };

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dxs[dir];
		int ny = y + dys[dir];

		if (canGo(nx, ny)) {
			area++;
			DFS(nx, ny, area);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	memset(grid, 0, sizeof(grid));
	memset(visit, false, sizeof(visit));

	int K;
	int area;
	vector<int> areas;
	cin >> M >> N >> K;

	int x_min, y_min, x_max, y_max;
	for (int i = 0; i < K; i++) {
		cin >> x_min >> y_min >> x_max >> y_max;

		for (int x = x_min; x < x_max; x++)
			for (int y = y_min; y < y_max; y++)
				grid[y][x] = 1;
	}

	for (int y = 0; y < M; y++)
		for (int x = 0; x < N; x++)
			if (!visit[y][x] && grid[y][x] == 0) {
				area = 1;
				DFS(x, y, area);
				areas.push_back(area);
			}

	sort(areas.begin(), areas.end());
	cout << areas.size() << endl;
	for (int A : areas)
		cout << A << " ";

	return 0;
}