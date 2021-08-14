#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, ans = 0;
	priority_queue <int, vector<int>, greater<int>> q;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		q.push(temp);
	}

	while (N--) {
		ans += q.top() * (N + 1);
		q.pop();
	}
	cout << ans;

	return 0;
}