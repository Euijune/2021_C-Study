#include <iostream>
using namespace std;

int seq[1001];
int dp[1001];

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> seq[i];
		dp[i] = 1;
	}

	int ans = dp[1];
	for (int i = 2; i <= N; i++)
		for (int j = i - 1; 1 <= j; j--)
			if (seq[j] < seq[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
				ans = max(ans, dp[i]);
			}
	
	cout << ans;

	return 0;
}