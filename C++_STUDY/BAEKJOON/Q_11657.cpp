#include <iostream>
#include <vector>
#include <limits.h>

#define endl '\n'

using namespace std;

typedef pair<int, int> pii;

const int INF = INT_MAX;
const int MAX_V = 501;
vector<pii> adj[MAX_V];

vector<long long> Bellman_ford(int st, int N) {
	vector<long long> dist(N + 1, INF);
	dist[0] = 1;	// �ð��� ������ �ǵ��� �� �ִ� ��� �� ���� 0�� �ȴ�
	dist[st] = 0;	// ������ ����

	for (int i = 0; i < N-1; i++) {
		for (int from = 1; from<=N; from++)
			for (pii& edge : adj[from]) {
				int to = edge.second;
				int cost = edge.first;

				if (dist[from] != INF)	// �ѹ��̶� ���� �����̶��
					dist[to] = min(dist[to], dist[from] + cost);
		}
	}

	// ���� N-1���� Ž�� ���� �߰��� �� ���� Ž���� �� �����Ͽ��µ�,
	// �Ÿ��� �ٲ�� ��찡 �ִٸ� '������������ ������ �� �ִ� ������' �߿� ���� ����Ŭ�� �����ϴ� ����̴�.
	// ���� �ð��� ������ ���� ������ �ǵ��� �� �ִ�.
	for (int from = 1; from <= N; from++)
		for (pii edge : adj[from]) {
			int to = edge.second;
			int cost = edge.first;

			if (dist[from] != INF && dist[to] > dist[from] + cost) {
				dist[0] = 0;	// �ð��� ������ �ǵ��� �� �ִ� ���
				break;
			}
		}

	return dist;
}

void PRINT(vector<long long> vec) {
	if (vec[0] == 1)
		for (unsigned int i = 2; i < vec.size(); i++)
			if (vec[i] == INF)
				cout << -1 << endl;
			else
				cout << vec[i] << endl;
	else
		cout << -1;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		adj[A].push_back({ C, B });
	}

	vector<long long> ans = Bellman_ford(1, N);

	PRINT(ans);

	return 0;
}