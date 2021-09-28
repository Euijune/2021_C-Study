#include <iostream>

using namespace std;

int main() {
	char word[101];
	cin >> word;

	for (int i = 0; i < 101 && word[i] != '\0'; i++) {
		if (word[i] >= 'a') {
			word[i] -= 32;
		}
		else {
			word[i] += 32;
		}
		cout << word[i];
	}

	/*char a = 'a';
	cout << a+'1';*/
	return 0;
}