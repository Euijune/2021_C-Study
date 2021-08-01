#include <iostream>
#include <queue>

using namespace std;
#define X first
#define Y second	// pair 에서 first, second 줄여쓰기 위해서. Ex) pair.X, pair.Y

int board[512][512] = {	// 세로축 x 가로축 y 좌상단 (0,0) 
	{1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
	{1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
	{1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
	{1, 1, 0, 0, 1, 0, 0, 0, 0, 0},
	{0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}	// 1이 파란 칸, 0이 빨간 칸에 대응
};
bool vis[512][512];	// 해당 칸 방문여부 저장
int row = 7, col = 10;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };	// 하 좌 상 우

int main() {
	queue<pair<int, int>> Q;
	vis[0][0] = 1;	// (0, 0)을 방문했다고 명시
	Q.push({ 0,0 });	// queue에 시작점 (0,0) 삽입

	while (!Q.empty()) {
		pair<int, int> cur = Q.front();	// 현 위치는 Q에 처음으로 들어간 좌표 (=front)
		Q.pop();
		cout << "(" << cur.X << ", " << cur.Y << ") -> \n";

		for (int dir = 0; dir < 4; dir++) {	// 상 하 좌 우 칸을 살펴볼 것이다.
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];	// (nx, ny) 로부터 인접한 상, 하, 좌, 우 칸 좌표로 변화

			if (nx < 0 || nx >= row || ny < 0 || ny >= col)	continue;	// 범위 밖일경우 넘어감
			if (vis[nx][ny] || board[nx][ny] != 1)		continue;	// 이미 방문한 칸이거나, 파란 칸이 아니면 넘어감
			
			vis[nx][ny] = 1;	// (nx, ny)를 방문했다고 명시
			Q.push({ nx, ny });
		}
	}

	return 0;
}