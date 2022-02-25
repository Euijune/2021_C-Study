#include <iostream>
#include <climits>
using namespace std;

int K, N;
int lan[10000];

bool isPossible(unsigned int length) {
	unsigned int taken = 0;
	for (int i = 0; i < K; i++) {
		if (lan[i] >= length)
			taken += lan[i] / length;
		if (taken >= N) return true;
	}
	return false;
}

int solve() {
	unsigned int left = 0, right = INT_MAX;
	unsigned int mid, ret;
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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> K >> N;

	for (int i = 0; i < K; i++)
		cin >> lan[i];

	cout << solve() << endl;

	return 0;
}