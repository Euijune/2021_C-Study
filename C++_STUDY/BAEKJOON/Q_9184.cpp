#include <iostream>
using namespace std;

int dp[21][21][21];	// -50 ~ 50, dp[50] = 0

void fillDp() {
	for (int i = 0; i < 21; i++)
		for (int j = 0; j < 21; j++)
			for (int k = 0; k < 21; k++)
				if (i == 0 || j == 0 || k == 0)
					dp[i][j][k] = 1;
				else if (i < j && j < k)
					dp[i][j][k] = dp[i][j][k - 1] + dp[i][j - 1][k - 1] - dp[i][j - 1][k];
				else
					dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] - dp[i - 1][j - 1][k - 1];
}

void w(int a, int b, int c) {
	int ans;
	if (a <= 0 || b <= 0 || c <= 0)
		ans = dp[0][0][0];
	else if (a > 20 || b > 20 || c > 20)
		ans = dp[20][20][20];
	else
		ans = dp[a][b][c];
	cout << "w(" << a << ", " << b << ", " << c << ") = " << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	fillDp();

	while (true) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == b && b == c && c == -1)
			break;

		w(a, b, c);		
	}

	return 0;
}