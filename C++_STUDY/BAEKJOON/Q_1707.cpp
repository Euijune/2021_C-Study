#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define endl '\n'
#define INIT -1
#define A 0
#define B 1

bool check_color(const vector<vector<int>>& graph, const vector<int>& color) {
	for (int curr = 0; curr < graph.size(); curr++)
		for (int adj : graph[curr])
			if (color[adj] != INIT && color[adj] == color[curr])
				return false;
	return true;
}

bool is_bipartite(const vector<vector<int>>& graph, vector<bool>& visit, vector<int>& color, int start) {
	queue<int> q;

	q.push(start);
	visit[start] = true;
	color[start] = A;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int adj : graph[curr]) {
			if (!visit[adj]) {
				visit[adj] = true;
				color[adj] = color[curr] == A ? B : A;
				q.push(adj);
			}
		}
	}

	return check_color(graph, color);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int K;
	cin >> K;

	while (K--) {
		int V, E;
		cin >> V >> E;

		vector<vector<int>> graph(V, vector<int>());
		vector<bool> visit(V, false);
		vector<int> color(V, INIT);

		for (int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			u--;
			v--;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		if (is_bipartite(graph, visit, color, 0))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}