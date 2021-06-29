#include <iostream>
using namespace std;

int main() {
	int total, bookPrice;
	cin >> total;
	
	for (int i = 0; i < 9; i++) {
		cin >> bookPrice;
		total -= bookPrice;
	}

	cout << total;

	return 0;
}