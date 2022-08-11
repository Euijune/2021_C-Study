#include<iostream>
using namespace std;

#define MAXN 100000

int seq[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, S;
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> seq[i];
	}

	int ans = MAXN;
	int start = 0, end = 0, sum = seq[start], length = 1;
	while (start <= end && end<N) {
		if (sum < S) {
			end++;
			length++;
			sum += seq[end];
		}
		else if (sum >= S) {
			ans = min(ans, length);
			length--;
			sum -= seq[start];
			start++;
		}
	}

	if (ans == MAXN)
		cout << 0;
	else
		cout << ans;

	return 0;
}