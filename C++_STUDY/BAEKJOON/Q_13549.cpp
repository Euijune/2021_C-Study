#include<iostream>
using namespace std;

#define MAX 100005
#define INF 987654321

int dp[MAX];

void tp(unsigned int curr) {
	int j = 2 * curr;
	while (j <= MAX) {
		dp[j] = min(dp[curr], dp[j]);
		j *= 2;
	}
}

int main() {
	int N, K;
	cin >> N >> K;

	for (int i = 0; i < MAX; i++)
		dp[i] = INF;

	dp[0] = N;
	for (unsigned int i = 1; i < MAX; i++) {
		if (i <= N)
			dp[i] = N - i;
		else
			if (i % 2 == 0)
				dp[i] = min(min(dp[i - 1] + 1, dp[i + 1] + 1), dp[i / 2]);
			else
				dp[i] = min(dp[i - 1] + 1, dp[i + 1] + 1);
		tp(i);
	}

	
	cout << dp[K];


	return 0;
}