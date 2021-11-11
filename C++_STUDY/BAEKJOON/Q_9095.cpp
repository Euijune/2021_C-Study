#include <iostream>
#include <memory.h>
using namespace std;

#define Ncond 12
int oneTwoThree[Ncond];

int OTT(int n) {
	if (oneTwoThree[n] == -1)
		oneTwoThree[n] = OTT(n - 3) + OTT(n - 2) + OTT(n - 1);

	return oneTwoThree[n];
}

int main() {
	int T;
	cin >> T;
	memset(oneTwoThree, -1, Ncond * sizeof(int));

	oneTwoThree[0] = 1;
	oneTwoThree[1] = 1;
	oneTwoThree[2] = 2;

	int n;
	while (T--) {
		cin >> n;
		cout << OTT(n) << endl;
	}

	return 0;
}

