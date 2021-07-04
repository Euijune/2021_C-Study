#include <iostream>
using namespace std;

int main() {
	int T, V, E, A;
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		A = 0;
		cin >> V >> E;
		A = 2 + E - V;
		cout << A << endl;
	}

	return 0;
}