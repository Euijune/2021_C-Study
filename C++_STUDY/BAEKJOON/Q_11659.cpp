#include <iostream>
using namespace std;

#define MAXN 100000
#define endl '\n'

int nums[MAXN];		// nums[i] : i번째 수까지의 누적 합

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	cin >> nums[0];

	for (int i = 1; i < N; i++) {
		int input;
		cin >> input;
		nums[i] = nums[i - 1] + input;
	}

	for (int i = 0; i < M; i++) {
		int l, r;
		cin >> l >> r;
		
		l--;
		r--;

		int p1 = nums[r];
		int p2 = l > 0 ? nums[l - 1] : 0;

		cout << p1 - p2 << endl;
	}


	return 0;
}