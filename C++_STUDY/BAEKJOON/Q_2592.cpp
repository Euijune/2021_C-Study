#include <iostream>

using namespace std;

int main() {
	int n, sum;
	pair<int, int> mode{ 0,0 };
	bool next;
	pair<int, int> num[10];

	sum = 0;
	for (int i = 0; i < 10; i++) {
		next = false;
		cin >> n;
		sum += n;

		for (pair<int, int>& elem : num) {
			if (elem.second > mode.second) {
				mode = elem;
			}
			if (elem.first == n) {
				elem.second++;
				next = true;
				break;
			}
		}
		
		if (next)	continue;
		else num[i] = { n,1 };
	}

	int avg = sum / 10;

	cout << avg << endl << mode.first;
	return 0;
}