#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAXN 1000
#define INF 100000000

typedef pair<int, int> pii;

int n, m, A, B;
vector<pii> adj[MAXN];
priority_queue<pii> pq;
vector<int> PARENT(MAXN, -1);	// parent[i] = i노드 바로 이전경로의 노드

vector<int> Dijkstra(int st) {
	// 최단거리 값을 담을 INF로 초기화한 벡터 선언 ret[도착점] = 최단거리
	vector<int> ret(n, INF);
	// 시작점 0으로 초기화, 우선순위 큐에 넣기
	ret[st] = 0;
	pq.push({0, st});
	PARENT[st] = st;

	//모든 정점을 돌 때까지 반복
	while (!pq.empty()) {
		// pq에 담긴 값 중 가장 cost가 작은 것 꺼내기
		int now = pq.top().second;
		// 마이너스를 붙여서 꺼낸 이유는 기본 우선순위 큐가 maxheap이라서 가장 작은 값을 꺼내기 위해 마이너스 붙임.
		// 30번행에서 마이너스를 붙여서 넣으므로 꺼낼 땐 기존 값으로 나옴.
		int weight = -pq.top().first;
		pq.pop();

		//사실상 시간이 단축되는 코드. 꺼낸 것 보다 현재  가중치가 작으면 돌필요 없어서 버림.
		if (weight > ret[now]) continue;

		for (int i = 0; i < adj[now].size(); i++) {
			int there = adj[now][i].second;
			int cost = adj[now][i].first + weight;
			// 만약 더 작은 가중치를 찾으면 ret 값을 바꿔주고 그 정점에서 한 번 더 탐색하기 위해 pq에 추가.
			if (cost < ret[there]) {
				ret[there] = cost;
				PARENT[there] = now;
				pq.push(make_pair(-cost, there));
			}
		}
	}
	return ret;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	cin >> m;
	
	for (int i = 0; i < m; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		adj[start-1].push_back({ cost, end-1 });	// index는 0부터, 도시번호는 1부터 시작하므로 맞춰준다
	}

	cin >> A >> B;

	vector<int> ret = Dijkstra(A-1);
	cout << ret[B - 1] << endl;	// A~B경로의 최소 비용
	
	vector<int> temp;	// B도시부터 parent를 따라 올라가면 순서가 반대로 나오므로, 제대로 출력하기 위한 벡터
	int curr = B-1;
	while (PARENT[curr] != curr) {
		temp.push_back(curr + 1);
		curr = PARENT[curr];
	}
	temp.push_back(curr + 1);

	cout << temp.size() << endl;	// A~B경로의 도시 수
	for (int i = temp.size() - 1; i >= 0; i--)
		cout << temp[i] << " ";

	return 0;
}