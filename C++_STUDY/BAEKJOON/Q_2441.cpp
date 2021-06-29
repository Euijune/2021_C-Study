#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int N, M;
	cin >> N;

	for (int i = N; i > 0; i--) {
		M = i;
		cout << setw(N-M+1);
		while (M) {
			cout << '*';
			M--;
		}
		cout << endl;
	}

	return 0;
}