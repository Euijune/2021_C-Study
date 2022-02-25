#include <iostream>
using namespace std;

int N, M, max_budget = 0;
int budget[10000];

bool isPossible(unsigned int maximum) {
	unsigned int taken = 0;
	for (int i = 0; i < N; i++) {
		if (budget[i] >= maximum)
			taken += maximum;
		else
			taken += budget[i];
		if (taken > M) return false;
	}
	return true;
}

int solve() {
	unsigned int left = 0, right = max_budget;
	unsigned int mid, ret;
	while (left <= right) {
		mid = (left + right) / 2;
		cout << mid << endl;
		if (isPossible(mid)) {
			ret = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	return ret;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> budget[i];
		max_budget = max(max_budget, budget[i]);
	}

	cin >> M;

	cout << solve() << endl;

	return 0;
}