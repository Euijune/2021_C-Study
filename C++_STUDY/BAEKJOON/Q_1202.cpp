#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MASS first
#define VALUE second
typedef pair<int, int> pii;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, K;
	ll ans = 0;
	cin >> N >> K;

	vector<pii> jewels;
	vector<int> bags;
	priority_queue<int> max_heap;

	int m, v;
	for (int i = 0; i < N; i++) {
		cin >> m >> v;
		jewels.push_back({ m,v });
	}
	sort(jewels.begin(), jewels.end());

	int s;
	for (int i = 0; i < K; i++) {
		cin >> s;
		bags.push_back(s);
	}
	sort(bags.begin(), bags.end());

	int indx = 0;
	for (int i = 0; i < K; i++) {
		while (indx < N && jewels[indx].MASS <= bags[i])
			max_heap.push(jewels[indx++].VALUE);
		if (!max_heap.empty()) {	// i번째 가방이 담을 수 있는 모든 보석의 값어치를 최대힙에 넣음
			ans += (ll)max_heap.top();
			max_heap.pop();
		}
	}

	cout << ans;

	return 0;
}