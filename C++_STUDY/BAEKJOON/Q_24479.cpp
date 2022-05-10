#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'

int cnt = 1;

void DFS(int curr, const vector<vector<int>>& graph, vector<bool>& visit, vector<int>& order) {
	for (int v : graph[curr])
		if (!visit[v]) {
			visit[v] = true;
			order[v] = cnt++;
			DFS(v, graph, visit, order);
		}
}

int main() {
	// For Fast I/O
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int V, E, R;	// V = N, E = M
	cin >> V >> E >> R;
	
	vector<vector<int>> graph(V + 1);
	vector<bool> visit(V + 1, false);
	vector<int> order(V + 1, 0);

	int v1, v2;
	for (int i = 0; i < E; i++) {
		cin >> v1 >> v2;
		// 무방향성 그래프
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	for (vector<int>& adj_list : graph)
		sort(adj_list.begin(), adj_list.end());

	visit[R] = true;
	order[R] = cnt++;
	DFS(R, graph, visit, order);

	for (int i = 1; i <= V; i++)
		cout << order[i] << endl;

	return 0;
}