#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define LOC first
#define FUEL second

typedef pair<int, int> pii;

vector<pii> gas_station;
priority_queue<int, vector<int>, less<int>> q;	// 주유소에서 채울 수 있는 연료의 양을 내림차순으로

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, dist, residual_fuel, ans = 0;
	cin >> N;
	gas_station.resize(N);

	for (int i = 0; i < N; i++)
		cin >> gas_station[i].LOC >> gas_station[i].FUEL;
	sort(gas_station.begin(), gas_station.end());

	cin >> dist >> residual_fuel;
	gas_station.push_back({ dist, 0 });

	for (int i = 0; i <= N; i++) {
		if (gas_station[i].LOC <= residual_fuel)
			q.push(gas_station[i].FUEL);
		else {
			if (!q.empty()) {
				residual_fuel += q.top();
				q.pop();
				ans++;
				i--;
			}
			else {
				cout << -1;
				exit(0);
			}
		}
	}

	cout << ans;

	return 0;
}