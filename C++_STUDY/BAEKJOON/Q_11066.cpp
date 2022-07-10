#include <iostream>
using namespace std;

#define INF 987654321
#define MAXK 500
#define endl '\n'

int files[MAXK];
int pSum[MAXK];	// pSum[i] = 0번째 파일부터 i번째 파일까지의 누적 합;

int dp(int l, int r) {
	if (l == r)
		return files[l];

	int ret = INF;

	int p1 = pSum[r];
	int p2 = l > 0 ? pSum[l - 1] : 0;
	int sum = p1 - p2;

	for (int i = l; i < r; i++)
		ret = min(ret, dp(l, i) + dp(i + 1, r) + sum);

	return ret;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int K;
		cin >> K;

		for (int i = 0; i < K; i++) {
			cin >> files[i];
			pSum[i] = files[i];

			if (i > 0)
				pSum[i] += pSum[i - 1];
		}

		int ans = INF;
		for (int i = 0; i < K; i++)
			ans = min(ans, dp(0, i) + dp(i + 1, K - 1));

		cout << ans << endl;
	}

	return 0;
}