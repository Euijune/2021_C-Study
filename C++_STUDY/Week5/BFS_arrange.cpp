#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
int N, M, V;

vector<int*> makeAdjList();
void freeList(vector<int*>& vec);
void printList(vector<int*>& vec);
void fillGraph(vector<int*>& graph);
void BFS(vector<int*>& graph, vector<int> visit);
void DFS(vector<int*>& graph, vector<int> visit);

int main() {
	
	// For fast IO
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> N >> M >> V;
	vector<int*> graph = makeAdjList();
	vector<int> visit(N + 1);	// 방문하면 1, 방문하지 않으면 0
	fillGraph(graph);

	/*printList(graph);
	cout << endl;*/

	DFS(graph, visit);
	cout << '\n';
	BFS(graph, visit);

	return 0;
}

vector<int*> makeAdjList() {
	vector<int*> temp(N + 1);
	for (int i = 0; i < N + 1; i++) {
		temp[i] = new int[N + 1];	// 어떤 두 정점을 잇는 간선이 유일할 때.
	}

	for (int i = 0; i < N + 1; i++) {
		for (int j = 0; j < N + 1; j++) {
			temp[i][j] = 0;
		}
	}

	return temp;
}

void printList(vector<int*>& vec) {
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
}

void freeList(vector<int*>& vec) {
	for (auto elem : vec) {
		delete elem;
	}
}

void fillGraph(vector<int*>& graph) {
	int a, b;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a][b] = 1;	// 1이면 간선으로 연결된 것임
		graph[b][a] = 1;	// 무방향 그래프
	}
}

void BFS(vector<int*>& graph, vector<int> visit) {
	queue<int> Q;
	Q.push(V);
	visit[V] = 1; // V번호를 가진 간선부터 방문한다고 명시

	while (!Q.empty()) {
		int cur = Q.front();	// 현 위치는 Q에 처음으로 들어간 좌표 (=front)
		Q.pop();
		cout << cur << " ";

		for (int i = 1; i < N + 1; i++) {
			int nCur = i;
			// 이미 방문했던 노드이거나, 현재 노드(cur)과 연결되지 않은 간선이면 넘어감.
			if (visit[nCur] == 1 || graph[cur][i] == 0)	continue;
			visit[nCur] = 1;
			Q.push(nCur);
		}
	}

	freeList(graph);
}

void DFS(vector<int*>& graph, vector<int> visit) {
	int count = 0;
	stack<int> S;
	S.push(V);
	visit[V] = 1;
	vector<int> cur_ascend(N);

	while (!S.empty()) {
		int cur = S.top();
		visit[cur] = 1;
		cur_ascend.clear();
		S.pop();
		cout << cur << " ";
		count++;
		if (count == N)	break;

		for (int i = 1; i < N + 1; i++) {
			int nCur = i;
			
			if (visit[nCur] == 1 || graph[cur][i] == 0)	continue;
			//visit[nCur] = 1;
			cur_ascend.push_back(nCur);
		}
		sort(cur_ascend.begin(), cur_ascend.end(), greater<int>());	// 방문할 수 있는 노드가 여러개면, 작은 것부터 방문
		for (int elem : cur_ascend) {
			S.push(elem);
		}
	}
}