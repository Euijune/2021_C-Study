#include <iostream>
#include <queue>
using namespace std;

int main() {
	// For fast IO
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> Q;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		Q.push(tmp);
	}

	while (!Q.empty()) {
		cout << Q.top() << "\n";
		Q.pop();
	}

	return 0;
}