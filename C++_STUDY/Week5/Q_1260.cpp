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
		graph[a].push_back(b);	// 1�̸� �������� ����� ����
		graph[b].push_back(a);	// ������ �׷���
	}

	for (int i = 1; i < N + 1; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
}

void BFS(int x) {
	queue<int> Q;
	Q.push(x);
	BFSvisit[x] = true; // x��ȣ�� ���� �������� �湮�Ѵٰ� ���

	while (!Q.empty()) {
		int cur = Q.front();	// �� ��ġ�� Q�� ó������ �� ��ǥ (=front)
		Q.pop();
		cout << cur << " ";

		for (int next : graph[cur]) {
			// �̹� �湮�ߴ� ����̰ų�, ���� ���(cur)�� ������� ���� �����̸� �Ѿ.
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