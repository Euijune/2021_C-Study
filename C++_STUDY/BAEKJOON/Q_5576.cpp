#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> W;
	vector<int> K;

	for (int i = 0; i < 10; i++) {
		int tmp;
		cin >> tmp;
		W.push_back(tmp);
	}
	sort(W.begin(), W.end());

	for (int j = 0; j < 10; j++) {
		int tmp;
		cin >> tmp;
		K.push_back(tmp);
	}
	sort(K.begin(), K.end());

	cout << W[9] + W[8] + W[7]<<" "<< K[9] + K[8] + K[7] << endl;

	return 0;
}