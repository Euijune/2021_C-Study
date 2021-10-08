#include <iostream>
using namespace std;

int main() {
	char word[101];
	cin >> word;

	int count = 0;
	for (char elem : word) {
		if (elem == '\0')
			break;
		cout << elem;
		count++;
		if (count == 10) {
			count = 0;
			cout << endl;
		}
		
	}

	return 0;
}