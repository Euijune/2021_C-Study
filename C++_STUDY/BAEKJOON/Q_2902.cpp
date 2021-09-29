#include <iostream>
#include <string>

using namespace std;

int main() {
	string longForm;
	bool PRINT = true;
	cin >> longForm;

	for (char elem : longForm) {
		if (PRINT) {
			cout << elem;
			PRINT = false;
		}
		if (elem == '-') {
			PRINT = true;
		}
	}

	return 0;
}