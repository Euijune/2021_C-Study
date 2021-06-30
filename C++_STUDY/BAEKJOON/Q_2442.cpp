#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 1; i < n+1; i++) {
		cout << setw(n - (i-1));
		for (int j = 0; j < 2 * i - 1; j++) {
			cout << '*';
		}
		cout << endl;
	}

	return 0;
}