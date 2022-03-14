#include <iostream>
#include <memory.h>
using namespace std;

typedef pair<int, int> pii;

#define W first
#define V second

pii things[100];
int dp[100][100001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	memset(dp, -1, sizeof(dp));
	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> things[i].W>>things[i].V;

	dp[0][0] = 0;
	dp[0][things[0].W] = things[0].V;

	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= K; j++) {
			pii thing = things[i];

			if (thing.W <= j)
				if (dp[i - 1][j - thing.W] == -1)
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = max(dp[i - 1][j - thing.W] + thing.V, dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];

		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= K; j++) {
			if (dp[i][j] == -1)
				cout << "- ";
			else
				cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	int ans = 0;
	for (int j = 0; j <= K; j++)
		ans = max(ans, dp[N - 1][j]);
	cout << ans;

	return 0;
}