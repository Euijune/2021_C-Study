#include <iostream>
#include <queue>
#include <string>

using namespace std;
#define R first
#define C second	// pair ���� first, second �ٿ����� ���ؼ�. Ex) pair.X, pair.Y

int board[101][101];
int dist[101][101];	// �ش� ĭ �湮���� ����
int row, col;
int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };	// �� �� �� ��

int main() {
	cin >> row >> col;

	for (int i = 1; i <= row; i++) {
		fill(dist[i], dist[i] + col + 1, -1);
		string temp;
		cin >> temp;
		for (int j = 1; j <= col; j++) {
			board[i][j] = temp[j - 1] - '0';
		}
	}

	queue<pair<int, int>> Q;
	Q.push({ 1, 1 });
	dist[1][1] = 0;

	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nR = cur.R + dr[dir];
			int nC = cur.C + dc[dir];

			if (nR < 1 || nR > row || nC < 1 || nC > col)	continue;
			if (dist[nR][nC] >= 0 || board[nR][nC] != 1)	continue;	// dist[nR][nC] >= 0 �̸� �湮�� ��

			dist[nR][nC] = dist[cur.R][cur.C] + 1;
			Q.push({ nR, nC });
		}
	}

	cout << dist[row][col] + 1;

	return 0;
}