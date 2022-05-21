#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_V 8000
#define INF 987654321

typedef pair<int, int> pii;

int N, E;
int v1, v2;
vector<pii> adj[MAX_V+1];
priority_queue<pii, vector<pii>, greater<pii>> pq;

vector<int> Dijkstra(int st) {
	vector<int> ret(N + 1, INF);
	ret[st] = 0;

	pq.push({ 0, st });

	while (!pq.empty()) {
		int dist = pq.top().first;
		int curr = pq.top().second;
		pq.pop();

		for (unsigned int i = 0; i < adj[curr].size(); i++) {
			int next = adj[curr][i].second;
			int cost = adj[curr][i].first + dist;

			if (cost < ret[next]) {
				ret[next] = cost;
				pq.push({ cost, next });
			}
		}
	}

	return ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
		adj[b].push_back({ c, a });
	}
	cin >> v1 >> v2;

	vector<int> ret1 = Dijkstra(1);
	vector<int> ret2 = Dijkstra(N);
	vector<int> ret3 = Dijkstra(v1);

	int ans;
	if (ret3[v2] == INF)
		ans = -1;
	else {
		ans = min(
			ret1[v1] + ret3[v2] + ret2[v2], // 1 -> v1 -> v2 -> N
			ret1[v2] + ret3[v2] + ret2[v1]	// 1 -> v2 -> v1 -> N
		);
		if (ans >= INF)
			ans = -1;
	}
	cout << ans;

	return 0;
}