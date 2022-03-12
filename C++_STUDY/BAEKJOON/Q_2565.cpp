#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

typedef pair<int, int> pii;

#define A_LOC first
#define B_LOC second

bool comp(const pii& lhs, const pii& rhs) {
	return (lhs.A_LOC < rhs.A_LOC);
}

int dp[100];
vector<pii> wires;

int main() {
	int N;
	cin >> N;
	wires.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> wires[i].A_LOC >> wires[i].B_LOC;
		dp[i] = 1;
	}

	sort(wires.begin(), wires.end(), comp);

	// dp[i] = i+1번째 수를 마지막으로 하는 최장 증가 부분수열의 길이
	int ans = dp[0];
	for (int i = 1; i < N; i++) {
		for (int j = i - 1; 0 <= j; j--)
			if (wires[j].B_LOC < wires[i].B_LOC)
				dp[i] = max(dp[i], dp[j] + 1);

		ans = max(dp[i], ans);
	}

	cout << N - ans;

	return 0;
}