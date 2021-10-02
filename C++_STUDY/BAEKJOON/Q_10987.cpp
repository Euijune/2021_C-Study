#include <iostream>
using namespace std;

int main() {
	char word[101];
	char vowels[5] = { 'a', 'e', 'i', 'o', 'u' };
	cin >> word;

	int indx = 0, ans = 0;
	while (word[indx] != '\0') {
		for (char vowel : vowels) {
			if (word[indx] == vowel) {
				ans++;
				break;
			}
		}
		indx++;
	}

	cout << ans;

	return 0;
}