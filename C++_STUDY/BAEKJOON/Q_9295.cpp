#include <iostream>
using namespace std;

int main() {
	int T, d1, d2;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> d1 >> d2;
		cout << "Case " << i + 1 << ": " << d1 + d2 << endl;
	}

	return 0;
}