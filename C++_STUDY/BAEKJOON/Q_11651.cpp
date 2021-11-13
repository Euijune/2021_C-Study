#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;


bool comp(pii& lhs, pii& rhs) {
	if (lhs.second == rhs.second)
		return lhs.first < rhs.first;
	return lhs.second < rhs.second;
}

int main() {
	// For fast I/O
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	vector<pii> v;

	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++)
		cin >> v[i].first >> v[i].second;

	sort(v.begin(), v.end(), comp);

	for (int i = 0; i < N; i++)
		cout << v[i].first << " " << v[i].second << '\n';

	return 0;
}