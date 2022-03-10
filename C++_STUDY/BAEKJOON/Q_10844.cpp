#include <iostream>
#include <memory.h>
using namespace std;

#define DIV 1000000000

int main() {
	int N, ans = 0;
	cin >> N;

	int dp[101][10];
	for (int i = 0; i < 101; i++)
		memset(dp[i], 0, sizeof(dp[i]));

	for (int j = 1; j < 10; j++)
		dp[1][j] = 1;

	for (int i = 2; i <= N; i++)
		for (int j = 0; j < 10; j++) {
			if (j > 0)
				dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % DIV;
			if (j < 9)
				dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % DIV;
			dp[i][j] %= DIV;
		}
	
	for (int j = 0; j < 10; j++)
		ans = (ans + dp[N][j]) % DIV;
	cout << ans;

	return 0;
}