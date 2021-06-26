#include <iostream>
#include <string>
using namespace std;

int main() {
	int testcase;
	int max;
	int numberOfPlayer;
	string name_max;
	cin >> testcase;

	while (testcase) {
		max = 0;
		name_max = "";
		cin >> numberOfPlayer;

		for (int i = 0; i < numberOfPlayer; i++) {
			int value;
			string name;
			cin >> value >> name;

			if (value > max) {
				max = value;
				name_max = name;
			}
		}
		cout << name_max << endl;
		testcase--;
	}

	return 0;
}