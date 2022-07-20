#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

#define MAXN 100
#define MAXC 100
#define MAXMEM 10000000

typedef pair<int, int> pii;

vector<int> bite(MAXN);
vector<int> cost(MAXN);
int dp[MAXN+1][MAXN*MAXC+1];

int main() {
	memset(dp, 0, sizeof(dp));
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> bite[i];

	for (int i = 0; i < N; i++)
		cin >> cost[i];

	for (int i = 1; i <= N; i++) {
		for (int c = 1; c <= N * MAXC; c++) {
			if (cost[i-1] <= c)
				dp[i][c] = max(bite[i-1] + dp[i-1][c - cost[i-1]], dp[i-1][c]);
			else
				dp[i][c] = dp[i - 1][c];
		}
	}

	for (int c = 1; c <= N * MAXC; c++) {
		if (dp[N][c] >= M) {
			cout << c;
			break;
		}
	}


	return 0;
}