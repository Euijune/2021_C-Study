#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> coin;
int dp[10001];	// dp[i][j] : 합이 i가 되는것들 중 마지막으로 쓴 동전이 coin[i]인 것. (오름차순 정렬)

int main() {
	cin >> n >> k;
	coin.resize(n);
	for (int i = 0; i < n; i++)
		cin >> coin[i];

	for (auto& c : coin)
		if (c <= k){
			dp[c]++;
			for (int j = c + 1; j <= k; j++)
				dp[j] += dp[j - c];
		}

	cout << dp[k];

	return 0;
}