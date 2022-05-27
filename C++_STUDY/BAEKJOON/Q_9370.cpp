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
vector<pair<int, int>> adj[MAX_V]; // ���� ����Ʈ ǥ�� pair(d, r) d: ������ ���� r: ������
priority_queue<pii, vector<pii>, greater<pii>> pq; // ���ͽ�Ʈ�� ����� �켱����ť
int candidates[MAX_T];			   // ������ �ĺ�
int dist[MAX_T];				   // ������������ �ִ� �Ÿ�

vector<int> Dijkstra(int st) {

	// ret[������] = �ִܰŸ�
	vector<int> ret(n+1, INF);
	// ������ 0���� �ʱ�ȭ
	ret[st] = 0;
	pq.push(make_pair(0, st));

	//��� ������ �� ������ �ݺ�
	while (!pq.empty()) {
		// pq�� ��� �� �� ���� weight�� ���� �� ������
		int now = pq.top().second;
		int weight = pq.top().first;
		pq.pop();

		//��ǻ� �ð��� ����Ǵ� �ڵ�. ���� �� ���� ����  ����ġ�� ������ ���ʿ� ��� ����.
		//if (weight > ret[now]) continue;

		for (unsigned int i = 0; i < adj[now].size(); i++) {
			int there = adj[now][i].second;
			int cost = adj[now][i].first + weight;
			// ���� �� ���� ����ġ�� ã���� ret ���� �ٲ��ְ� �� �������� �� �� �� Ž���ϱ� ���� pq�� �߰�.
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

	//�Է�
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
			adj[b].push_back(make_pair(d, a));	// �����⼺
		}

		for (int i = 0; i < t; i++)
			cin >> candidates[i];
		sort(candidates, candidates + t);

		//�Լ�ȣ��
		vector<int> MIN = Dijkstra(s);	// s���� ���, ��� ������ ����

		// ������ʹ� g-h�� �մ� ���ΰ� ����.
		for (int i = 0; i < adj[g].size(); i++)
			if (adj[g][i].second == h)
				adj[g].erase(adj[g].begin() + i);
		for (int i = 0; i < adj[h].size(); i++)
			if (adj[h][i].second == h)
				adj[h].erase(adj[h].begin() + i);
		vector<int> S = Dijkstra(s);	// s���� ���
		vector<int> G = Dijkstra(g);	// g���� ���
		vector<int> H = Dijkstra(h);	// h���� ���

		//Ȯ�ο�
		/*cout << endl;
		cout << "MIN: ";
		PRINT(MIN);
		cout << "S: ";
		PRINT(S);
		cout << "G: ";
		PRINT(G);
		cout << "H: ";
		PRINT(H);*/

		// ����?
		for (int i = 0; i < t; i++) {
			//cout << "������ " << candidates[i] << ": ";
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