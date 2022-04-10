#include <iostream>
using namespace std;

typedef long long ll;

ll countBelow(ll m, ll N) {		// m���� ���� �� count
	ll cnt = 0;
	for (ll row = 1; row < N + 1; row++)
		/*
			row: A�� row��° �� A[row]
			row��° ���� ���ҵ��� ��� row * 1���� row * N������ �����̴�.
			��, (m-1) / row�� ��� N�߿� �ּڰ��� �ٷ� row�࿡�� m���� ���� ���� �����̴�.
			Ex) N = 3, m = 7�� ���, row = 1�϶� (m-1)/row �� ���� 6, ���� A[1]�� 1*1, 1*2, 1*3 �� m���� �۴�.
									 row = 2�϶� (m-1)/row �� ���� 3, ���� A[2]�� 2*1, 2*2, 2*3 �� m���� �۴�.
									 row = 3�϶� (m-1)/row �� ���� 2, ���� A[3]�� 3*1, 3*2 �� m���� �۴�.
		*/
		cnt += min(((m - 1) - (m - 1) % row) / row, N);
	return cnt;
}

int main() {
	int N, k;
	cin >> N >> k;

	ll left = 0, right = (ll)N * N;

	while (left <= right) {
		ll mid = (left + right) / 2;

		if (countBelow(mid, N) >= k)
			right = mid - 1;
		else
			left = mid + 1;
	}

	cout << right;

	return 0;
}