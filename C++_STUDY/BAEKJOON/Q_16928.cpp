#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
using namespace std;

#define MAXNUM 100
#define MAXCOUNT 100
typedef pair<int, int> pii;

vector<vector<int>> graph (MAXNUM+1, vector<int>()); // ������6ĭ, (��ٸ� or ��)
int is_ladder_or_snake[MAXNUM + 1];	// is_ladder_or_snake[i] : i��° ���ڿ��� ��ٸ� �Ǵ� ������ ����� ���� (������ 0)
int visit[MAXNUM + 1];	// visit[i] : i��° ���ڱ��� �����ϱ� ���� ������ �ϴ� �ֻ����� �ּ� Ƚ��

void BFS() {
	for (int i = 0; i <= MAXNUM; i++)
		visit[i] = MAXCOUNT;
	
	queue<pii> q;

	int curr = 0;
	int next = 1;
	q.push({ curr, next });
	visit[next] = 0;

	while (!q.empty()) {
		pii tmp = q.front();
		q.pop();
		curr = tmp.second;

		for (int i = 0; i < graph[curr].size(); i++) {
			next = graph[curr][i];

			if (visit[next] == MAXCOUNT) {
				q.push({ curr, next });
			}

			if (next == is_ladder_or_snake[curr])
				visit[next] = min(visit[next], visit[curr]);
			else
				visit[next] = min(visit[next], visit[curr] + 1);
		}
	}

	cout << visit[100];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;	

	for (int i = 0; i < N+M; i++) {
		int start, end;
		cin >> start >> end;
		graph[start].push_back(end);
		is_ladder_or_snake[start] = end;
	}

	for (int i = 1; i <= MAXNUM; i++)
		if (!is_ladder_or_snake[i])		// ���� i��° ĭ�� ��ٸ��� ���� �ִٸ�, �ֻ����� ���� �ʿ䰡 ����.
			for (int j = i + 1; j <= i + 6 && j <= 100; j++)
				graph[i].push_back(j);

	BFS();

	return 0;
}