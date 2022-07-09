#include <iostream>
#include <vector>
using namespace std;

#define MAXN 1000000
#define MAXM 1000
typedef long long ll;

ll pSum[MAXN];    // pSum[i] = 0번째 수부터 i번째 수까지의 누적합
vector<vector<int>> remain(MAXM);	// remain[i] = 0번부터 j번째까지의 누적합중 M으로 나눈 나머지가 i인 것의 인덱스 j가 저장된 벡터 (j<N)

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	ll ans = 0;
	
	for (int i = 0; i < N; i++) {
		cin >> pSum[i];
		if (i > 0)
			pSum[i] += pSum[i - 1];

		// 나머지가 같은 부분합(pSum)끼리 묶는과정
		remain[pSum[i] % M].push_back(i);
	}

	for (int r = 0; r < M; r++)
		if (!remain[r].empty()) {
			ll n = remain[r].size();
			ans += n * (n - 1) / 2;
		}

	// M으로 나눴을 때 나머지가 0인 누적 합 구간 추가
	ans += remain[0].size();

	cout << ans;

	return 0;
}