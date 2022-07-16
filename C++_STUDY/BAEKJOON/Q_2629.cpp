#include <iostream>
using namespace std;

#define MAXN 30
#define MAXW 40000

int weight[MAXN+1];
int dp[MAXN+1][MAXW+1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	std::cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> weight[i];

	for (int i = 0; i < MAXN+1; i++)
		for (int w = 0; w < MAXW + 1; w++)
			if (i == 0 || w == 0)
				dp[i][w] = 0;
			else if (w == weight[i])
				dp[i][w] = w;
			else if (w > weight[i]) {
				bool case1 = dp[i - 1][w - weight[i]] + weight[i] == w;
				bool case2 = dp[i - 1][weight[i] + w] - weight[i] == w;
				dp[i][w] = case1 || case2 ? w : dp[i - 1][w];
			}
			else if (w < weight[i]) {
				bool case1 = weight[i] - dp[i - 1][weight[i] - w] == w;
				bool case2 = dp[i - 1][weight[i] + w] - weight[i] == w;
				dp[i][w] = case1 || case2 ? w : dp[i - 1][w];
			}


	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int w;
		cin >> w;
		if (dp[N][w] == w)
			cout << "Y ";
		else
			cout << "N ";
	}

	return 0;
}