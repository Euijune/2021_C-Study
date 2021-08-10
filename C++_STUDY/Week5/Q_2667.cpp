#include <iostream>
#include <string>
#include <queue>
#include <functional>
using namespace std;
#define X first
#define Y second

int N, num = 0;
string board[25];
int vis[25][25];
priority_queue<int, vector<int>, greater<int>> Size;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
queue<pair<int, int>> Q;

void BFS(pair<int, int> startP);

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		fill(vis[i], vis[i] + N + 1, 0);
		cin >> board[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == '1' && vis[i][j] == 0) {
				pair<int, int> startingPoint = { i,j };
				BFS(startingPoint);
				num++;
			}
		}
	}
	cout << num << endl;

	while(!Size.empty()) {
		cout << Size.top() << "\n";
		Size.pop();
	}

	return 0;
}

void BFS(pair<int, int> startP) {
	int area = 0;
	vis[startP.X][startP.Y] = 1;
	Q.push({ startP.X, startP.Y });

	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		area++;

		for (int i = 0; i < 4; i++) {
			int nX = cur.X + dx[i];
			int nY = cur.Y + dy[i];

			if (nX < 0 || nX >= N || nY < 0 || nY >= N)		continue;
			if (board[nX][nY] == '0' || vis[nX][nY] == 1)	continue;

			vis[nX][nY] = 1;
			Q.push({ nX, nY });
		}
	}
	Size.push(area);
}