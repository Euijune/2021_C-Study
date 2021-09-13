#include <iostream>
#include <queue>
using namespace std;

int main() {
	char N[11];
	priority_queue <int, vector<int>, less<int>> Q;
	cin >> N;
	
	for (int i = 0; i < 10; i++) {
		int n = N[i] - '0';
		if (0 <= n && n <= 9) {
			Q.push(n);
		}
	}

	int length = Q.size();
	for (int i = 0; i < length; i++) {
		cout << Q.top();
		Q.pop();
	}

	return 0;
}