#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define endl '\n'
typedef pair<int, int> pii;

const int INF = 987654321;
const int MAX_V = 2001;
const int MAX_T = 100;

int n, m, t, s, g, h;
vector<pair<int, int>> adj[MAX_V]; // 인접 리스트 표현 pair(d, r) d: 도로의 길이 r: 도착점
priority_queue<pii, vector<pii>, greater<pii>> pq; // 다익스트라에 사용할 우선순위큐
int candidates[MAX_T];			   // 목적지 후보
int dist[MAX_T];				   // 목적지까지의 최단 거리

vector<int> Dijkstra(int st) {

	// ret[도착점] = 최단거리
	vector<int> ret(n+1, INF);
	// 시작점 0으로 초기화
	ret[st] = 0;
	pq.push(make_pair(0, st));

	//모든 정점을 돌 때까지 반복
	while (!pq.empty()) {
		// pq에 담긴 값 중 가장 weight가 작은 것 꺼내기
		int now = pq.top().second;
		int weight = pq.top().first;
		pq.pop();

		//사실상 시간이 단축되는 코드. 꺼낸 것 보다 현재  가중치가 작으면 돌필요 없어서 버림.
		//if (weight > ret[now]) continue;

		for (unsigned int i = 0; i < adj[now].size(); i++) {
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

void PRINT(vector<int> vec) {
	for (unsigned int i = 1; i < vec.size(); i++) {
		if (vec[i] == INF)cout << "INF ";
		else cout << vec[i] << ' ';
	}
	cout << endl;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	//입력
	int T;
	cin >> T;
	while (T--) {
		int gh_dist = 0;
		cin >> n >> m >> t;
		cin >> s >> g >> h;

		for (int i = 0; i < m; i++) {
			int a, b, d;
			cin >> a >> b >> d;
			if (a == g && b == h || a == h && b == g)
				gh_dist = d;
			adj[a].push_back(make_pair(d, b));
			adj[b].push_back(make_pair(d, a));	// 무방향성
		}

		for (int i = 0; i < t; i++)
			cin >> candidates[i];
		sort(candidates, candidates + t);

		//함수호출
		vector<int> MIN = Dijkstra(s);	// s에서 출발, 모든 간선이 존재

		// 여기부터는 g-h를 잇는 도로가 없음.
		for (int i = 0; i < adj[g].size(); i++)
			if (adj[g][i].second == h)
				adj[g].erase(adj[g].begin() + i);
		for (int i = 0; i < adj[h].size(); i++)
			if (adj[h][i].second == h)
				adj[h].erase(adj[h].begin() + i);
		vector<int> S = Dijkstra(s);	// s에서 출발
		vector<int> G = Dijkstra(g);	// g에서 출발
		vector<int> H = Dijkstra(h);	// h에서 출발

		//확인용
		/*cout << endl;
		cout << "MIN: ";
		PRINT(MIN);
		cout << "S: ";
		PRINT(S);
		cout << "G: ";
		PRINT(G);
		cout << "H: ";
		PRINT(H);*/

		// 정답?
		for (int i = 0; i < t; i++) {
			//cout << "목적지 " << candidates[i] << ": ";
			int case1, case2;

			if (S[g] == INF || H[candidates[i]] == INF)
				case1 = INF;
			else
				case1 = S[g] + gh_dist + H[candidates[i]];

			if (S[h] == INF || G[candidates[i]] == INF)
				case2 = INF;
			else
				case2 = S[h] + gh_dist + G[candidates[i]];

			dist[i] = min(case1, case2);
			//cout << case1 << " " << case2 << endl;
		}	// S -> G -> H -> Destination

		for (int i = 0; i < t; i++)
			if (MIN[candidates[i]] == dist[i] && dist[i] != INF)
				cout << candidates[i] << " ";
		cout << endl;
	}
	
	return 0;
}