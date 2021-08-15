#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	int N, K, count = 0;
	cin >> N >> K;
	priority_queue <int, vector<int>, less<int>> q;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		q.push(temp);
	}


	while (K) {
		if (K >= q.top()) {
			K -= q.top();
			count++;
		}
		else {
			q.pop();
		}
	}

	cout << count;

	return 0;
}