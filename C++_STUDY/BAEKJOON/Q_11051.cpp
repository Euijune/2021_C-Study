#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp;	// dp[i][j] = iCj

int main() {
	int N, K;
	cin >> N >> K;
	dp.resize(N+1);

	for (int i = 0; i <= N; i++) {
		int SIZE = min(i, K) + 1;
		dp[i].resize(SIZE);	// nCk = (n-1)C(k-1) + (n-1)Ck

		for (int j = 0; j < SIZE; j++)
			if (j == 0 || j == i)	// nC0 = 1, nCn = 1
				dp[i][j] = 1;
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
	}

	cout << dp[N][K];

	return 0;
}