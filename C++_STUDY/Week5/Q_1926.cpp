#include <iostream>
#include <stack>

using namespace std;
#define R first
#define C second

int board[501][501];
int vis[501][501];
int row, col, maxArea = 0, paintingNum = 0;
int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };
stack<pair<int, int> > S;
void DFS(pair<int, int> start);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> row >> col;

	for (int i = 0; i < row; i++) {
		fill(vis[i], vis[i] + col + 1, 0);
		for (int j = 0; j < col; j++)   cin >> board[i][j];
	}

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (board[i][j] == 1 && vis[i][j] == 0) {
                pair<int, int> startPoint = { i, j };
                DFS(startPoint);
                paintingNum++;
            }
        }
    }

    cout << paintingNum << '\n' << maxArea;

	return 0;
}

void DFS(pair<int, int> start) {
    int i = start.R, j = start.C, area = 0;

    vis[i][j] = 1;
    S.push({ i, j });

    while (!S.empty()) {
        pair<int, int> cur = S.top(); S.pop();
        area++;

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.R + dr[dir];
            int ny = cur.C + dc[dir];
            if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
            if (vis[nx][ny] == 1 || board[nx][ny] != 1) continue;
            vis[nx][ny] = 1;
            S.push({ nx,ny });
        }
    }

    if (area > maxArea) maxArea = area;
}