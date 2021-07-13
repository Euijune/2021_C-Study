#include <iostream>

using namespace std;

int main() {
	int ride, quit, train, max;

	train = 0;
	max = 0;
	for (int i = 0; i < 4; i++) {
		cin >> quit >> ride;
		train -= quit;
		train += ride;
		if (max < train) {
			max = train;
		}
	}
	cout << max;

	return 0;
}