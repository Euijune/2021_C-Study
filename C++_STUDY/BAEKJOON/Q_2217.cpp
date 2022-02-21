#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const int& lhs, const int& rhs) {
	return lhs < rhs;
}

vector<int> rope;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, ans = 0;
	cin >> N;
	rope.resize(N);

	for (int i = 0; i < N; i++)
		cin >> rope[i];

	sort(rope.begin(), rope.end(), cmp);

	for (int i = N - 1; i >= 0; i--) {
		int cnt = N - i;
		ans = max(ans, cnt * rope[i]);
	}
	cout << ans;

	return 0;
}