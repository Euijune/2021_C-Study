#include <iostream>
using namespace std;

int seq[10001];
int dp[10001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, ans = 0;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> seq[i];

	dp[0] = 0;
	dp[1] = seq[1];
	dp[2] = seq[1] + seq[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 1], max(dp[i - 2] + seq[i], dp[i - 3] + seq[i - 1] + seq[i]));
		ans = max(dp[i], ans);
	}

	/*for (int i = 0; i <= n; i++)
		cout << dp[i][0] << " " << dp[i][1] << endl;*/
	cout << ans;

	return 0;
}