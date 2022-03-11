#include <iostream>
#include <string>
using namespace std;

int dp[1001][1001];

int main() {
	string str1, str2;
	cin >> str1;
	cin >> str2;
	str1 = '_' + str1;
	str2 = '_' + str2;

	int L1 = str1.size(), L2 = str2.size();

	for (int i = 1; i < L1; i++)
		for (int j = 1; j < L2; j++)
			if (str1[i] == str2[j])
				dp[i][j] = dp[i-1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

	int lcs = dp[L1-1][L2-1];
	cout << lcs;

	return 0;
}