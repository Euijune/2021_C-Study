#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> coin;
int dp[10001];	// dp[i][j] : ���� i�� �Ǵ°͵� �� ���������� �� ������ coin[i]�� ��. (�������� ����)

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