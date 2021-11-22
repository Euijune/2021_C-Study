#include <iostream>
#include <memory.h>
using namespace std;

int* S;
int k;

void makeSet();

int main() {
	
	do {
		cin >> k;
		S = new int[k];

		for (int i = 0; i < k; i++)
			cin >> S[i];

		makeSet();

	} while (k != 0);

	return 0;
}

void makeSet() {
	int indxs[6] = { 0,1,2,3,4,5 };
	int items[6] = { S[1], S[2], S[3], S[4], S[5], S[6] };

	while (indxs[0] != k-5) {
		for (int i = 1; i < k; i++)
			if (indxs[i] == k - (5 - i)) {
				indxs[i - 1]++;
				indxs[i] = indxs[i - 1] + 1;
			}

		for (int indx : indxs)
			cout << indx << " ";
		cout << endl;

		indxs[5]++;
	}
}