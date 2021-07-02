#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);// cin cout 동기화 해제
	cin.tie(0);
	int T, s, n, q, p, sum;
	cin >> T;

	for (int i = 0; i < T; i++) {
		sum = 0;
		cin >> s;
		sum += s;

		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> q >> p;
			sum += q * p;
		}
		cout << sum << endl;
	}

	return 0;
}