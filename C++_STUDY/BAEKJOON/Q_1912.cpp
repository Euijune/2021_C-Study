#include <iostream>
#include <vector>
using namespace std;

vector<int> seq;
vector<int> dp;

int main() {
	int n, ans;
	cin >> n;
	seq.resize(n);
	dp.resize(n);
	for (int i = 0; i < n; i++)
		cin >> seq[i];

	dp[0] = seq[0];
	ans = seq[0];

	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i-1]+seq[i], seq[i]);
		ans = max(ans, dp[i]);
	}

	cout << ans;

	return 0;
}