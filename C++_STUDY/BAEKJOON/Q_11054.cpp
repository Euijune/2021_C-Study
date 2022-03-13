#include <iostream>
using namespace std;

int seq[1000];
int dp[1000][2];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> seq[i];
		dp[i][0] = 1;
		dp[i][1] = 1;
	}

	// dp[i][0] : i번째 수를 마지막으로 하는 가장 큰 부분증가수열의 길이
	for (int i = 1; i < N; i++)
		for (int j = i - 1; 0 <= j; j--)
			if (seq[j] < seq[i])
				dp[i][0] = max(dp[i][0], dp[j][0] + 1);

	
	// dp[i][1] : i번째 수를 시작으로 하는 가장 큰 부분감소수열의 길이
	for (int i = N - 2; 0 <= i; i--)
		for (int j = i + 1; j < N; j++)
			if (seq[j] < seq[i])
				dp[i][1] = max(dp[i][1], dp[j][1] + 1);

	int ans = 0;
	for (int i = 0; i < N; i++)
		ans = max(ans, dp[i][0] + dp[i][1] - 1);

	cout << ans;

	return 0;
}