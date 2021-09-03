#include <iostream>

using namespace std;

int main() {
	int N, min_num = 1000000, max_num = -1000000;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;

		if (temp < min_num) {
			min_num = temp;
		}
		if (temp > max_num) {
			max_num = temp;
		}

	}

	cout << min_num << " " << max_num;

	return 0;
}