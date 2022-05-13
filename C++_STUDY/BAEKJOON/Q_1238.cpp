#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 987654321;
#define endl '\n'

vector<int> Dijkstra(int st, int N, vector<vector<pair<int, int>>>& adj) {
	priority_queue <pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;

	// �ִܰŸ� ���� ���� INF�� �ʱ�ȭ�� ���� ���� ret[������] = �ִܰŸ�
	vector<int> ret(N+1, INF);
	// ������ 0���� �ʱ�ȭ, �켱���� ť�� �ֱ�
	ret[st] = 0;
	pq.push(make_pair(0, st));

	//��� ������ �� ������ �ݺ�
	while (!pq.empty()) {
		// pq�� ��� �� �� ���� weight�� ���� �� ������
		int now = pq.top().second;
		// ���̳ʽ��� �ٿ��� ���� ������ �⺻ �켱���� ť�� maxheap�̶� ���� ���� ���� ������ ���� ���̳ʽ� ����.
		// 37���࿡�� ���̳ʽ��� �ٿ��� �����Ƿ� ���� �� ���� ������ ����.
		int weight = pq.top().first;
		pq.pop();

		//��ǻ� �ð��� ����Ǵ� �ڵ�. ���� �� ���� ����  ����ġ�� ������ ���ʿ� ��� ����.
		if (weight > ret[now]) continue;

		for (int i = 0; i < adj[now].size(); i++) {
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

	// X��° �������� �ڽ��� ������ ���ư��� �ִ� �Ÿ�
	vector<int> Xtoi = Dijkstra(X, N, adj);

	// itoX[i] : i(1 <= i <= N, i !=X)��° �������� X��° ������ �̵��ϴ� �ִ� �Ÿ�
	// ans: N���� �л��� �� ���� ���µ� ���� ���� �ɸ��� �л��� �ҿ�ð�
	vector<int> itoX = Dijkstra(X, N, adj_reverse);
	for (int i = 1; i <= N; i++)
		ans = max(itoX[i] + Xtoi[i], ans);

	cout << ans;

	return 0;
}