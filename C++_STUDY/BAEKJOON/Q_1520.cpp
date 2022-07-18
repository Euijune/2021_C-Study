#include <iostream>
#include <queue>
using namespace std;

#define MAXN 500
#define MAXM 500

typedef pair<int, int> pii;

int M, N;
int map[MAXM][MAXN];
int dp[MAXM][MAXN];		// dp[i][j] = i행j열까지 도달하는 경우의 수
bool visit[MAXM][MAXN];
int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };


class comp {
public:
	bool operator()(const pii& lhs, const pii& rhs) {
		return map[lhs.first][lhs.second] < map[rhs.first][rhs.second];		// 높이가 높은 지점이 Queue의 앞으로 오도록 정렬
	}
};

bool inRange(int r, int c) {
	return 0 <= r && r < M && 0 <= c && c < N;
}

int search(int r, int c) {
	int ret1 = 1;
	int ret2 = 0;
	int count = 0;

	for (int dir = 0; dir < 4; dir++) {
		int nr = r + dr[dir];
		int nc = c + dc[dir];

		if (inRange(nr, nc) && map[nr][nc] > map[r][c]) {
			count++;
			ret1 = max(dp[nr][nc], ret1);
			ret2 += dp[nr][nc];
		}
	}

	if (count > 1)
		return ret2;
	else
		return ret1;
}

void solve(int m, int n) {
	priority_queue<pii, vector<pii>, comp> Q;
	Q.push({ m, n });
	visit[m][n] = true;

	while (!Q.empty()) {
		pii curr = Q.top();
		Q.pop();

		int r = curr.first;
		int c = curr.second;
		int h = search(r, c);

		dp[r][c] = h;

		for (int dir = 0; dir < 4; dir++) {
			int nr = r + dr[dir];
			int nc = c + dc[dir];

			if (inRange(nr, nc) && map[r][c] > map[nr][nc] && !visit[nr][nc]) {
				Q.push({ nr, nc });
				visit[nr][nc] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N;

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	solve(0, 0);
	cout << dp[M - 1][N - 1];

	return 0;
}