#include <iostream>
using namespace std;

int dp[1001];

int main() {
	int N, K;
	cin >> N >> K;

	dp[0] = 1;
	for (int i = 1; i <= N; i++)
		dp[i] = dp[i - 1] * i;

	cout << dp[N] / (dp[N - K] * dp[K]);

	return 0;
}