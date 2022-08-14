#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

#define MAXN 1000000

int dp[MAXN+1];

void calculate(int indx, int cnt) {
	int idx1 = indx + 1;
	int idx2 = (indx * 2) > MAXN ? 0 : indx * 2;
	int idx3 = (indx * 3) > MAXN ? 0 : indx * 3;
	int idxs[3] = {idx1, idx2, idx3};
	for (int i = 0; i < 3; i++)
		if (dp[idxs[i]] == -1)
			dp[idxs[i]] = cnt + 1;
}

vector<int> find_ans(int N) {
	int cnt = dp[N];
	vector<int> ret;
	ret.push_back(N);
	while (N != 1) {
		cnt--;
		if (dp[N - 1] == cnt)
			N--;
		else if (N % 2 == 0 && dp[N / 2] == cnt)
			N /= 2;
		else if (N % 3 == 0 && dp[N / 3] == cnt)
			N /= 3;
		ret.push_back(N);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);

	memset(dp, -1, sizeof(dp));

	int N;
	cin >> N;

	int cnt = 0;
	dp[1] = cnt;
	while (dp[N] == -1) {
		for (int i = 1; i <= MAXN; i++)
			if (dp[i] == cnt)
				calculate(i, cnt);
		cnt++;
	}
	cout << dp[N] << endl;

	vector<int> ans = find_ans(N);
	for (int elem : ans)
		cout << elem << " ";

	return 0;
}