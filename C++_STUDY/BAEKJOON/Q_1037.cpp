#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N, max = 2, min = 1000000;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		if (tmp > max) {
			max = tmp;
		}
		if (tmp < min) {
			min = tmp;
		}
	}

	cout << min << " " << max << " " << min * max;

	return 0;
}