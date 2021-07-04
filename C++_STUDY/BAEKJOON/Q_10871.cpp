#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;

	vector<int> vec(n);

	for (int& elem : vec) {
		cin >> elem;
		if (elem < x) cout << elem << " ";	
	}

	return 0;
}