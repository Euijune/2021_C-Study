#include <iostream>

using namespace std;

int main() {
	int N, sum, count;
	cin >> N;

	sum = 0;
	count = 0;

	while (count <= N) {
		for (int i = count; i <= N; i++) {
			sum = sum + i + count;
		}
		count++;
	}
	
	cout << sum << endl;

	return 0;
}