#include <iostream>
using namespace std;

int main() {
	int T;
	char string[1001];

	cin >> T;
	while (T--) {
		int indx_last = 0;
		cin >> string;

		cout << string[0];
		for (int i = 0; i < 1001 && string[i] != '\0'; i++) {
			indx_last = i;
		}
		cout << string[indx_last] << endl;;
	}

	return 0;
}