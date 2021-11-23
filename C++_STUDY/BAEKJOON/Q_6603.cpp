#include <iostream>
#include <memory.h>
using namespace std;

int* S;
int indxes[6] = { 0,1,2,3,4,5 };
int k;

void makeSet();

int main() {
	// For fast I/O
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	do {
		cin >> k;
		S = new int[k];

		for (int i = 0; i < k; i++)
			cin >> S[i];

		makeSet();
		cout << '\n';

	} while (k != 0);

	return 0;
}

void makeSet() {
	for (int c1 = 0; c1 <= k - 6; c1++)
		for (int c2 = c1 + 1; c2 <= k - 5; c2++)
			for (int c3 = c2 + 1; c3 <= k - 4; c3++)
				for (int c4 = c3 + 1; c4 <= k - 3; c4++)
					for (int c5 = c4 + 1; c5 <= k - 2; c5++)
						for (int c6 = c5 + 1; c6 <= k - 1; c6++)
							cout << S[c1] << " " << S[c2] << " " << S[c3] << " " << S[c4] << " " << S[c5] << " " << S[c6] << '\n';
}