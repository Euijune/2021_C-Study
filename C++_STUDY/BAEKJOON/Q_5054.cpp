#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int store_num, min = 100, max = 0, temp;
		cin >> store_num;

		for (int i = 0; i < store_num; i++) {
			cin >> temp;
			min = temp < min ? temp : min;
			max = temp > max ? temp : max;
		}
		cout << (max - min) * 2 << endl;
	}

	

	return 0;
}