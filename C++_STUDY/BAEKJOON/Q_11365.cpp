#include <iostream>
#include <string>
using namespace std;

int main() {
	char sentence[501];
	string save;

	while (sentence != "END\0") {
		save = "";
		cin.getline(sentence, 500);

		for (char elem : sentence) {
			if (elem == '\0') {
				save += '\n';
				break;
			}
			save = elem + save;
		}
		if (save == "DNE\n") {
			return 0;
		}
		else {
			cout << save;
		}
	}

	return 0;
}