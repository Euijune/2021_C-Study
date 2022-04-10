#include <iostream>
using namespace std;

typedef long long ll;

ll countBelow(ll m, ll N) {		// m보다 작은 수 count
	ll cnt = 0;
	for (ll row = 1; row < N + 1; row++)
		/*
			row: A의 row번째 행 A[row]
			row번째 행의 원소들은 모두 row * 1부터 row * N까지의 수들이다.
			즉, (m-1) / row의 몫과 N중에 최솟값이 바로 row행에서 m보다 작은 수의 개수이다.
			Ex) N = 3, m = 7인 경우, row = 1일때 (m-1)/row 의 몫은 6, 따라서 A[1]의 1*1, 1*2, 1*3 이 m보다 작다.
									 row = 2일때 (m-1)/row 의 몫은 3, 따라서 A[2]의 2*1, 2*2, 2*3 이 m보다 작다.
									 row = 3일때 (m-1)/row 의 몫은 2, 따라서 A[3]의 3*1, 3*2 이 m보다 작다.
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