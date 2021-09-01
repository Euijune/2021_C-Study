#include <iostream>
#include <vector>
using namespace std;

void deci2bin(int N, vector<int>& binary) {
	if (N == 0) {
		binary.push_back(0);
	}
	else if (N == 1) {
		binary.push_back(1);
	}
	else if (N % 2 == 0) {
		binary.push_back(0);
		deci2bin(N / 2, binary);
	}
	else if (N % 2 == 1) {
		binary.push_back(1);
		deci2bin((N - 1) / 2, binary);
	}
}

int main() {
	int T, N;
	cin >> T;
	

	while (T--) {

		cin >> N;

		vector<int> binary;
		deci2bin(N, binary);

		indx = 0
		for (int elem : binary) {
			if (elem) {
				cout << indx << " ";
			}
			indx++;
		}
	}
	
	return 0;
}