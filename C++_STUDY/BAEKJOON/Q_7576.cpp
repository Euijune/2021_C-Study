#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

#define RIPE 1
#define UNRIPE 0
#define NONE -1

int N, M;
int number_of_ripe_tomato = 0, number_of_none = 0;
int box[1000][1000];
int date[1000][1000];
queue<pii> q;

bool inRange(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < M;
}

bool canGo(int r, int c) {
	return inRange(r, c) && box[r][c] == UNRIPE;
}

void BFS() {
	int drs[4] = { 0, 0, 1, -1 };
	int dcs[4] = { 1, -1, 0, 0 };

	date[q.front().first][q.front().second] = 0;

	while (!q.empty()) {
		pii curr = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = curr.first + drs[i];
			int nc = curr.second + dcs[i];

			if (canGo(nr, nc)) {
				box[nr][nc] = RIPE;
				date[nr][nc] = date[curr.first][curr.second] + 1;
				number_of_ripe_tomato++;
				q.push({ nr, nc });
			}
		}
	}
}

int searchMaxDate() {
	int MAX = -1;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			MAX = max(MAX, date[i][j]);
	return MAX;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> M >> N;

	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++) {
			cin >> box[r][c];
			if (box[r][c] == RIPE) {
				number_of_ripe_tomato++;
				q.push({ r, c });
			}
			else if (box[r][c] == NONE)
				number_of_none++;
		}

	BFS();

	if (N * M - number_of_none == number_of_ripe_tomato)
		cout << searchMaxDate();
	else
		cout << -1;

	return 0;
}