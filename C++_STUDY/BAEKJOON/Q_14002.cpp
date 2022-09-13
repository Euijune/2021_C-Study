#include <iostream>
using namespace std;

#define MAXN 1000
#define endl '\n'

int seq[MAXN];
int dp[MAXN];
bool visit[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> seq[i];
		dp[i] = 1;
		visit[i][i] = true;
	}

	int ans_idx = 0;
	for (int i = 1; i < N; i++)
		for (int j = i - 1; 0 <= j; j--)
			if (seq[j] < seq[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				ans_idx = dp[ans_idx] < dp[i] ? i : ans_idx;
				for (int k = 0; k < i; k++)
					visit[i][k] = visit[j][k];
			}

	cout << dp[ans_idx] << endl;
	for (int i = 0; i < N; i++) {
		if (visit[ans_idx][i])
			cout << seq[i] << " ";
	}

	return 0;
}