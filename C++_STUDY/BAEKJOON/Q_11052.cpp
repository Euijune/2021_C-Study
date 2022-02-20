#include <iostream>
using namespace std;

int cardPack[1001];
int dp[1001];

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> cardPack[i];

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= i; j++)
			dp[i] = max(dp[i], dp[i-j] + cardPack[j]);

	cout << dp[N];
		
	return 0;
}