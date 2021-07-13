#include <iostream>

using namespace std;

int main() {
	int max, temp, count = 1;
	cin >> max;

	for (int i = 2; i <=9; i++) {
		cin >> temp;
		if (max < temp) {
			max = temp;
			count = i;
		}
	}
	cout << max << endl << count;

	return 0;
}