#include <iostream>
using namespace std;

int main() {
	int n1, n2, n3;
	int min = 1000000, max = 1;
	cin >> n1 >> n2 >> n3;

	if (n1 <= min) {
		min = n1;
	}
	else if (n1 >= max) {
		max = n1;
	}

	if (n2 <= min) {
		min = n2;
	}
	else if (n2 >= max) {
		max = n2;
	}

	if (n3 <= min) {
		min = n3;
	}
	else if (n3 >= max) {
		max = n3;
	}

	cout << min << " " << max << " " << n1 << " " << n2 << " " << n3;
	return 0;
}