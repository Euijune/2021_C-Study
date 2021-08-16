#include <iostream>

using namespace std;

int main() {
	int N, count = 0, indx = 0;
	int bag[2] = { 5, 3 };
	cin >> N;

	while (N) {
		if (indx >= 2) {
			count = -1;
			break;
		}
		if (N % 5 == 0) {
			N -= bag[0];
			count++;
		}
		else if (N % 3 == 0) {
			N -= bag[1];
			count++;
		}
		else if (N >= bag[indx]) {
			N -= bag[indx];
			count++;
		}
		else {
			indx++;
		}
	}

	cout << count << endl;
	
	return 0;
}