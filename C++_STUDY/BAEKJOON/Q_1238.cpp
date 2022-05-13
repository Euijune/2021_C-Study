#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 987654321;
#define endl '\n'

vector<int> Dijkstra(int st, int N, vector<vector<pair<int, int>>>& adj) {
	priority_queue <pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;

	// 최단거리 값을 담을 INF로 초기화한 벡터 선언 ret[도착점] = 최단거리
	vector<int> ret(N+1, INF);
	// 시작점 0으로 초기화, 우선순위 큐에 넣기
	ret[st] = 0;
	pq.push(make_pair(0, st));

	//모든 정점을 돌 때까지 반복
	while (!pq.empty()) {
		// pq에 담긴 값 중 가장 weight가 작은 것 꺼내기
		int now = pq.top().second;
		// 마이너스를 붙여서 꺼낸 이유는 기본 우선순위 큐가 maxheap이라서 가장 작은 값을 꺼내기 위해 마이너스 붙임.
		// 37번행에서 마이너스를 붙여서 넣으므로 꺼낼 땐 기존 값으로 나옴.
		int weight = pq.top().first;
		pq.pop();

		//사실상 시간이 단축되는 코드. 꺼낸 것 보다 현재  가중치가 작으면 돌필요 없어서 버림.
		if (weight > ret[now]) continue;

		for (int i = 0; i < adj[now].size(); i++) {
			int there = adj[now][i].second;
			int cost = adj[now][i].first + weight;
			// 만약 더 작은 가중치를 찾으면 ret 값을 바꿔주고 그 정점에서 한 번 더 탐색하기 위해 pq에 추가.
			if (cost < ret[there]) {
				ret[there] = cost;
				pq.push(make_pair(cost, there));
			}
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M, X;
	cin >> N >> M >> X;

	vector<vector<pair<int, int>>> adj(N + 1);
	vector<vector<pair<int, int>>> adj_reverse(N + 1);
	int ans = -1;

	for (int i = 0; i < M; i++) {
		int v_start, v_end, time;
		cin >> v_start >> v_end >> time;
		adj[v_start].push_back({ time, v_end });
		adj_reverse[v_end].push_back({ time, v_start });
	}

	// X번째 마을에서 자신의 마을로 돌아가는 최단 거리
	vector<int> Xtoi = Dijkstra(X, N, adj);

	// itoX[i] : i(1 <= i <= N, i !=X)번째 마을에서 X번째 마을로 이동하는 최단 거리
	// ans: N명의 학생들 중 오고 가는데 가장 오래 걸리는 학생의 소요시간
	vector<int> itoX = Dijkstra(X, N, adj_reverse);
	for (int i = 1; i <= N; i++)
		ans = max(itoX[i] + Xtoi[i], ans);

	cout << ans;

	return 0;
}