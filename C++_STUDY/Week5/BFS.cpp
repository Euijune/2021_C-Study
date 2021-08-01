#include <iostream>
#include <queue>

using namespace std;
#define X first
#define Y second	// pair ���� first, second �ٿ����� ���ؼ�. Ex) pair.X, pair.Y

int board[512][512] = {	// ������ x ������ y �»�� (0,0) 
	{1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
	{1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
	{1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
	{1, 1, 0, 0, 1, 0, 0, 0, 0, 0},
	{0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}	// 1�� �Ķ� ĭ, 0�� ���� ĭ�� ����
};
bool vis[512][512];	// �ش� ĭ �湮���� ����
int row = 7, col = 10;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };	// �� �� �� ��

int main() {
	queue<pair<int, int>> Q;
	vis[0][0] = 1;	// (0, 0)�� �湮�ߴٰ� ���
	Q.push({ 0,0 });	// queue�� ������ (0,0) ����

	while (!Q.empty()) {
		pair<int, int> cur = Q.front();	// �� ��ġ�� Q�� ó������ �� ��ǥ (=front)
		Q.pop();
		cout << "(" << cur.X << ", " << cur.Y << ") -> \n";

		for (int dir = 0; dir < 4; dir++) {	// �� �� �� �� ĭ�� ���캼 ���̴�.
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];	// (nx, ny) �κ��� ������ ��, ��, ��, �� ĭ ��ǥ�� ��ȭ

			if (nx < 0 || nx >= row || ny < 0 || ny >= col)	continue;	// ���� ���ϰ�� �Ѿ
			if (vis[nx][ny] || board[nx][ny] != 1)		continue;	// �̹� �湮�� ĭ�̰ų�, �Ķ� ĭ�� �ƴϸ� �Ѿ
			
			vis[nx][ny] = 1;	// (nx, ny)�� �湮�ߴٰ� ���
			Q.push({ nx, ny });
		}
	}

	return 0;
}