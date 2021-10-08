#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	char* numlist = new char[N + 1];
	int sum = 0;
	cin >> numlist;

	for (int i = 0; i < N + 1; i++) {
		if (numlist[i] == '\0')
			break;
		int n = numlist[i] - '0';
		sum += n;
	}

	cout << sum;

	return 0;
}