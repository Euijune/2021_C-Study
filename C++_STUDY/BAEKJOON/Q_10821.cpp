#include <iostream>
using namespace std;

int main() {
	int count = 0;
	char str[101];

	cin >> str;
	
	for (char elem : str) {
		if (elem == ',') {
			count++;
		}
	}
	count++;

	cout << count;

	return 0;
}