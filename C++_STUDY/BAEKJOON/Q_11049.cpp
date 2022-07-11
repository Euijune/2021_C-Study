#include <iostream>
#include <memory.h>
#include <climits>
using namespace std;

#define MAXN 500
typedef pair<int, int> pii;
typedef long long ll;

pii matrix[MAXN];
ll cache[MAXN + 1][MAXN + 1];

ll matmul(int l, int m, int r) {
	// dp(a, b), dp(c, d) : matmul(a, c, d);
	int N, M, K;
	N = matrix[l].first;
	M = matrix[m].first;
	K = matrix[r].second;
	return N * M * K;
}

ll dp(int l, int r) {
	if (l == r || l > r)
		return 0;

	if (r - l == 1)
		return matmul(l, r, r);

	ll& ret = cache[l][r];
	if (ret != -1)	return ret;

	ret = INT_MAX;

	for (int i = l; i < r; i++)
		ret = min(ret, dp(l, i) + dp(i + 1, r) + matmul(l, i + 1, r));

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	memset(cache, -1, sizeof(cache));

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int r, c;
		cin >> r >> c;
		matrix[i] = { r, c };
	}

	ll ans;
	if (N == 1)
		ans = 0;
	else {
		ans = INT_MAX;

		for (int i = 0; i < N - 1; i++)
			ans = min(ans, dp(0, i) + dp(i + 1, N - 1) + matmul(0, i + 1, N - 1));
	}

	cout << ans;

	return 0;
}