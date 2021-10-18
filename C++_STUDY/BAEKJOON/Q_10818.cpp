#include <iostream>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, min_num = 1000000, max_num = -1000000;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;

		min_num = min_num > temp ? temp : min_num;
		max_num = max_num < temp ? temp : max_num;
	}

	cout << min_num << " " << max_num;

	return 0;
}