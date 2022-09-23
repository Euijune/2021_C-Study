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
vector<int> PARENT(MAXN, -1);	// parent[i] = i��� �ٷ� ��������� ���

vector<int> Dijkstra(int st) {
	// �ִܰŸ� ���� ���� INF�� �ʱ�ȭ�� ���� ���� ret[������] = �ִܰŸ�
	vector<int> ret(n, INF);
	// ������ 0���� �ʱ�ȭ, �켱���� ť�� �ֱ�
	ret[st] = 0;
	pq.push({0, st});
	PARENT[st] = st;

	//��� ������ �� ������ �ݺ�
	while (!pq.empty()) {
		// pq�� ��� �� �� ���� cost�� ���� �� ������
		int now = pq.top().second;
		// ���̳ʽ��� �ٿ��� ���� ������ �⺻ �켱���� ť�� maxheap�̶� ���� ���� ���� ������ ���� ���̳ʽ� ����.
		// 30���࿡�� ���̳ʽ��� �ٿ��� �����Ƿ� ���� �� ���� ������ ����.
		int weight = -pq.top().first;
		pq.pop();

		//��ǻ� �ð��� ����Ǵ� �ڵ�. ���� �� ���� ����  ����ġ�� ������ ���ʿ� ��� ����.
		if (weight > ret[now]) continue;

		for (int i = 0; i < adj[now].size(); i++) {
			int there = adj[now][i].second;
			int cost = adj[now][i].first + weight;
			// ���� �� ���� ����ġ�� ã���� ret ���� �ٲ��ְ� �� �������� �� �� �� Ž���ϱ� ���� pq�� �߰�.
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
		adj[start-1].push_back({ cost, end-1 });	// index�� 0����, ���ù�ȣ�� 1���� �����ϹǷ� �����ش�
	}

	cin >> A >> B;

	vector<int> ret = Dijkstra(A-1);
	cout << ret[B - 1] << endl;	// A~B����� �ּ� ���
	
	vector<int> temp;	// B���ú��� parent�� ���� �ö󰡸� ������ �ݴ�� �����Ƿ�, ����� ����ϱ� ���� ����
	int curr = B-1;
	while (PARENT[curr] != curr) {
		temp.push_back(curr + 1);
		curr = PARENT[curr];
	}
	temp.push_back(curr + 1);

	cout << temp.size() << endl;	// A~B����� ���� ��
	for (int i = temp.size() - 1; i >= 0; i--)
		cout << temp[i] << " ";

	return 0;
}