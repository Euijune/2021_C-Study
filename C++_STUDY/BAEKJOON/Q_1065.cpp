#include <iostream>
using namespace std;

int find_hansu(int N) {
	int cnt = min(N, 99);

	for (int number = 111; number <= min(N, 999); number++) {
		int units = number % 10;
		int tens = (number % 100 - units) / 10;
		int hundreds = (number % 1000 - (units + tens * 10)) / 100;

		if ((hundreds - tens) == (tens - units))
			cnt++;
	}

	return cnt;
}

int main() {
	int N;
	cin >> N;

	int ans = find_hansu(N);
	cout << ans;

	return 0;
}