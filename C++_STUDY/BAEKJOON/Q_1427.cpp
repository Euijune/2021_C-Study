#include <iostream>
#include <queue>
using namespace std;

int main() {
	char N[10];
	priority_queue <int, vector<int>, greater<int>> Q;
	cin >> N;
	
	for (int i = 0; i < 10; i++) {
		int n = N[i] - '0';
		cout << "test : " << n << endl;
		if (0 <= n && n <= 9) {
			Q.push(n);
		}
	}

	cout << Q.size() << endl;
	for (int i = 0; i < Q.size(); i++) {
		cout << Q.top();
		Q.pop();
	}


	return 0;
}