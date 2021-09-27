#include <iostream>
using namespace std;

int main() {
	char word[101];
	cin >> word;

	for (int i = 0; i < 101; i++) {
		if (word[i] == '\0') { 
			cout << i;
			break; 
		}
	}

	return 0;
}