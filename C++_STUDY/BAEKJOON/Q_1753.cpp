#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_V 20005
#define INF 987654321

int V, E, K;
vector<pair<int, int>> adj[MAX_V];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

vector<int> Dijkstra(int st) {
	vector<int> ret(V + 1, INF);

	ret[st] = 0;
	pq.push({ 0, st });

	while (!pq.empty()) {
		int w = pq.top().first;		// x = w
		int now = pq.top().second;	// U = now
		pq.pop();

		for (int i = 0; i < adj[now].size(); i++) {
			int there = adj[now][i].first;	// V = there
			int ww = adj[now][i].second;	// W = ww

			if (w+ww < ret[there]) {
				ret[there] = w+ww;
				pq.push({ w+ww, there});
			}
		}
	}

	return ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> V >> E >> K;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ v, w });
	}

	vector<int> ans = Dijkstra(K);

	for (int i = 1; i < ans.size(); i++) {
		if (ans[i] == INF)	cout << "INF\n";
		else				cout << ans[i] << '\n';
	}

	return 0;
}