#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
int N, M, V;
bool DFSvisit[1001];
bool BFSvisit[1001];
vector<vector<int>> graph(1001);

void fillGraph();
void BFS(int x);
void DFS(int x);

int main() {

	// For fast IO
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> V;
	
	memset(DFSvisit, false, sizeof(DFSvisit));
	memset(BFSvisit, false, sizeof(BFSvisit));
	fillGraph();
	
	DFS(V);
	cout << '\n';
	BFS(V);

	return 0;
}

void fillGraph() {
	int a, b;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a].push_back(b);	// 1이면 간선으로 연결된 것임
		graph[b].push_back(a);	// 무방향 그래프
	}

	for (int i = 1; i < N + 1; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
}

void BFS(int x) {
	queue<int> Q;
	Q.push(x);
	BFSvisit[x] = true; // x번호를 가진 간선부터 방문한다고 명시

	while (!Q.empty()) {
		int cur = Q.front();	// 현 위치는 Q에 처음으로 들어간 좌표 (=front)
		Q.pop();
		cout << cur << " ";

		for (int next : graph[cur]) {
			// 이미 방문했던 노드이거나, 현재 노드(cur)과 연결되지 않은 간선이면 넘어감.
			if (BFSvisit[next])	continue;
			BFSvisit[next] = true;
			Q.push(next);
		}
	}
}

void DFS(int x) {
	int cur = x;
	DFSvisit[x] = true;	
	cout << cur << " ";

	for (int next : graph[cur]) {
		if (DFSvisit[next])	continue;
		DFS(next);
	}
}