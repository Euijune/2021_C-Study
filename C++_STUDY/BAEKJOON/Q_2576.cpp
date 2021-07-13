#include <iostream>

using namespace std;

int main() {
	int n, min_odd = 101, sum = 0;

	for (int i = 0; i < 7; i++ ) {
		cin >> n;
		if (n % 2 == 1) { // È¦¼ö
			if (n < min_odd) {
				min_odd = n;
			}
			sum += n;
		}
	}

	if (sum)	cout << sum << endl << min_odd;
	else		cout << -1;


	return 0;
}