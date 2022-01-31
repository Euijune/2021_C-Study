#include <iostream>
#include <queue>
#include <tuple>
#include <memory.h>
using namespace std;
typedef tuple<int, int, int> ti3;

#define RIPE 1
#define UNRIPE 0
#define NONE -1

int M, N, H;
int number_of_ripe_tomato = 0, number_of_none = 0;
int box[100][100][100];
int date[100][100][100];
queue<ti3> q;

bool inRange(int h, int r, int c) {
	return 0 <= h && h < H && 0 <= r && r < N && 0 <= c && c < M;
}

bool canGo(int h, int r, int c) {
	return inRange(h, r, c) && box[h][r][c] == UNRIPE;
}

void BFS() {
	int dhs[6] = { 0, 0, 0, 0, 1, -1 };
	int drs[6] = { 0, 0, 1, -1, 0, 0 };
	int dcs[6] = { 1, -1, 0, 0, 0, 0 };
	int h, r, c;

	while (!q.empty()) {
		tie(h, r, c) = q.front();
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nh = h + dhs[i];
			int nr = r + drs[i];
			int nc = c + dcs[i];

			if (canGo(nh, nr, nc)) {
				box[nh][nr][nc] = RIPE;
				date[nh][nr][nc] = date[h][r][c] + 1;
				number_of_ripe_tomato++;
				q.push(make_tuple(nh, nr, nc));
			}
		}
	}

}

int searchMaxDate() {
	int MAX = 0;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < M; k++)
				MAX = max(MAX, date[i][j][k]);
	return MAX;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(date, -1, sizeof(date));

	cin >> M >> N >> H;

	for (int i = 0; i < H; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < M; k++) {
				cin >> box[i][j][k];
				if (box[i][j][k] == RIPE) {
					number_of_ripe_tomato++;
					date[i][j][k] = 0;
					q.push(make_tuple(i, j, k));
				}
				else if (box[i][j][k] == NONE)
					number_of_none++;
			}

	BFS();
	if (H * N * M - number_of_none > number_of_ripe_tomato)	// 토마토가 모두 익지 않았다면
		cout << -1;
	else
		cout << searchMaxDate();

	return 0;
}