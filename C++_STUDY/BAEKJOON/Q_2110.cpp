#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C, ans = 0;
vector<int> houses;

bool isPossible(int dist) {
	int cnt = 1;
	int prev = houses[0];

	for (int i = 1; i < N; i++) {
		if (houses[i] - prev >= dist) {
			cnt++;
			prev = houses[i];
		}
		if (cnt >= C) return true;
	}
	return false;
}

int solve() {
	int left = 0, right = houses[N-1];
	int mid, ret = 0;

	while (left <= right) {
		mid = (left + right) / 2;
		if (isPossible(mid)) {
			ret = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	return ret;
}

bool comp(const int& lhs, const int& rhs) {
	return lhs < rhs;
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> C;
	houses.resize(N);

	for (int i = 0; i < N; i++)
		cin >> houses[i];
	sort(houses.begin(), houses.end(), comp);

	cout << solve();

	return 0;
}