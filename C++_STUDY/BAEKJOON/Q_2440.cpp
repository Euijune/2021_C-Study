#include <iostream>
using namespace std;

int main() {
	int N, M;
	cin >> N;

	for (int i = N; i > 0; i--) {
		M = i;
		while (M) {
			cout << '*';
			M--;
		}
		cout << endl;
	}

	return 0;
}