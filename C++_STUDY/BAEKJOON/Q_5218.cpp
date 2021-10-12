#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;

	char word1[21], word2[21];
	int distances[21];

	while (T) {
		cin >> word1 >> word2;
		int i = 0;

		do {
			char elem1 = word1[i];
			char elem2 = word2[i];
			int distance = (elem2 >= elem1) ? (elem2 - elem1) : (elem2 + 26 - elem1);

			distances[i] = distance;
			i++;
		} while (word1[i] != '\0');

		cout << "Distances:";
		for (int indx = 0; indx < i; indx++) {
			cout << " " << distances[indx];
		}
		cout << endl;

		T--;
	}

	return 0;
}