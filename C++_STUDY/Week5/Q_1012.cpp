#include <iostream>
#include <string>
#include <queue>
using namespace std;
#define X first
#define Y second

int col, row, napaCabbage, num;
int board[50][50];
bool vis[50][50];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
queue<pair<int, int>> Q;

void BFS(pair<int, int> start);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T) {
		cin >> col >> row >> napaCabbage;
		num = 0;

		for (int i = 0; i < row; i++) {
			fill(board[i], board[i] + col + 1, 0);
			fill(vis[i], vis[i] + col + 1, false);
		}

		for (int i = 0; i < napaCabbage; i++) {
			int x, y;
			cin >> x >> y;
			board[y][x] = 1;
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (board[i][j] == 1 && vis[i][j] == false) {
					BFS({ i, j });
					num++;
					cout << endl;
				}
			}
		}

		cout << num << endl;
		T--;
	}

	return 0;
}

void BFS(pair<int, int> start) {
	vis[start.X][start.Y] = true;
	Q.push({ start.X, start.Y });

	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		cout << "(" << cur.X << ", " << cur.Y << ") =>";

		for (int dir = 0; dir < 4; dir++) {
			int nX = cur.X + dx[dir];
			int nY = cur.Y + dy[dir];

			if (nX < 0 || nX >= row || nY < 0 || nY >= col)	continue;
			if (board[nX][nY] == 0 || vis[nX][nY] == true)	continue;

			vis[nX][nY] = true;
			Q.push({ nX, nY });
		}
	}
}