#include <iostream>
using namespace std;

int main() {
	int N, M;
	cin >> N;

	for (int i = 1; i < N+1; i++) {
		M = i;
		while (M) {
			cout << '*';
			M--;
		}
		cout << endl;
	}

	return 0;
}