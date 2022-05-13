#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define endl '\n'

void BFS(int curr, vector<vector<int>>& graph, vector<bool>& visit, vector<int>& order, queue<int>& q) {
	int cnt = 1;
	while (!q.empty()) {
		int curr = q.front();
		order[curr] = cnt++;
		q.pop();
		for (int next : graph[curr])
			if (!visit[next]) {
				visit[next] = true;
				q.push(next);
			}
	}
}

int main() {
	// For Fast I/O
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M, R;
	cin >> N >> M >> R;

	vector<vector<int>> graph(N + 1);
	vector<bool> visit(N + 1, false);
	vector<int> order(N + 1, 0);
	queue<int> q;

	int v1, v2;
	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	for (vector<int>& adj_list : graph)
		sort(adj_list.begin(), adj_list.end());
	
	q.push(R);
	visit[R] = true;
	BFS(R, graph, visit, order, q);

	for (int i = 1; i<order.size(); i++)
		cout << order[i] << endl;

	return 0;
}