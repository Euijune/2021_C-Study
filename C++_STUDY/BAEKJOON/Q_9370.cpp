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
int candidates[MAX_T];	// ������ �ĺ�
int dist[MAX_T];		// ������������ �ִ� �Ÿ�

vector<int> Dijkstra(int st, vector<pii> adj[]) {
	priority_queue<pii, vector<pii>, greater<pii>> pq; 
	vector<int> ret(n + 1, INF);
	ret[st] = 0;
	pq.push(make_pair(0, st));

	while (!pq.empty()) {
		int now = pq.top().second;
		int weight = pq.top().first;
		pq.pop();

		if (weight > ret[now]) continue;

		for (unsigned int i = 0; i < adj[now].size(); i++) {
			int there = adj[now][i].second;
			int cost = adj[now][i].first + weight;
			if (cost < ret[there]) {
				ret[there] = cost;
				pq.push(make_pair(cost, there));
			}
		}
	}
	return ret;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	//�Է�
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m >> t;
		cin >> s >> g >> h;

		vector<pii> adj[MAX_V]; // ���� ����Ʈ ǥ�� pair(d, r) d: ������ ���� r: ������

		for (int i = 0; i < m; i++) {
			int a, b, d;
			cin >> a >> b >> d;
			adj[a].push_back(make_pair(d, b));
			adj[b].push_back(make_pair(d, a));	// �����⼺
		}

		for (int i = 0; i < t; i++)
			cin >> candidates[i];
		sort(candidates, candidates + t);

		vector<int> S = Dijkstra(s, adj);	// s���� ���
		vector<int> G = Dijkstra(g, adj);	// g���� ���
		vector<int> H = Dijkstra(h, adj);	// h���� ���

		for (int i = 0; i < t; i++) {
			int case1, case2;

			if (S[g] == INF || H[candidates[i]] == INF)
				case1 = INF;
			else
				case1 = S[g] + G[h] + H[candidates[i]];

			if (S[h] == INF || G[candidates[i]] == INF)
				case2 = INF;
			else
				case2 = S[h] + H[g] + G[candidates[i]];

			dist[i] = min(case1, case2);
		}	// (s -> g -> h -> Destination) OR (s -> h -> g -> Destination)

		for (int i = 0; i < t; i++)
			if (S[candidates[i]] == dist[i] && dist[i] != INF)
				cout << candidates[i] << " ";
		cout << endl;
	}
	
	return 0;
}