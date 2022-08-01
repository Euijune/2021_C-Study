#include <iostream>
using namespace std;

#define MAXV 400
#define NULL 0
#define MAXDIST 999999999

int V, E;
int ans = MAXDIST;
int graph[MAXV+1][MAXV+1];
bool visit[MAXV + 1];

void DFS(int start, int curr, int dist) {
	//cout << "curr: " << curr << endl;
	visit[curr] = true;

	for (int next = 1; next <= V; next++) {
		int cost = graph[curr][next];
		if (cost != NULL) {
			//cout << "next: " << next << endl;
			if (next == start)
				ans = min(ans, dist + cost);
			if (!visit[next])
				DFS(start, next, dist + cost);
		}
	}

	visit[curr] = false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = c;
	}

	/*cout << endl;
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;*/

	for (int i = 1; i <= V; i++) {
		DFS(i, i, 0);
		visit[i] = true;
		//cout << "ans : " << ans << endl << endl;;
	}

	if (ans == MAXDIST)
		ans = -1;
	cout << ans;

	return 0;
}