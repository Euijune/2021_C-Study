#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int min = 100;
		int sum = 0;

		for (int i = 0; i < 7; i++) {
			int tmp;
			cin >> tmp;

			if (tmp % 2 == 0) {
				sum += tmp;
				if (min > tmp) {
					min = tmp;
				}
			}
		}
		cout << sum<<" "<<min << endl;
	}

	return 0;
}