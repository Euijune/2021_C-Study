#include <iostream>
#include <vector>
using namespace std;

#define MAXN 1000000
#define MAXM 1000
typedef long long ll;

ll pSum[MAXN];    // pSum[i] = 0��° ������ i��° �������� ������
vector<vector<int>> remain(MAXM);	// remain[i] = 0������ j��°������ �������� M���� ���� �������� i�� ���� �ε��� j�� ����� ���� (j<N)

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

		// �������� ���� �κ���(pSum)���� ���°���
		remain[pSum[i] % M].push_back(i);
	}

	for (int r = 0; r < M; r++)
		if (!remain[r].empty()) {
			ll n = remain[r].size();
			ans += n * (n - 1) / 2;
		}

	// M���� ������ �� �������� 0�� ���� �� ���� �߰�
	ans += remain[0].size();

	cout << ans;

	return 0;
}