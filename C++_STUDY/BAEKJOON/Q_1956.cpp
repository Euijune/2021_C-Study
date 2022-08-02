#include <iostream>
#include <vector>
using namespace std;

#define MAXV 400
#define MAXDIST 999999999

int V, E;
int cost[MAXV][MAXV];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> V >> E;

	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			cost[i][j] = MAXDIST;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		cost[--a][--b] = c;
	}

	for (int node = 0; node < V; node++) {
		for (int s = 0; s < V; s++) {
			if (s == node)
				continue;
			for (int e = 0; e < V; e++) {
				if (e == node || s == e)
					continue;
				cost[s][e] = min(cost[s][e], cost[s][node] + cost[node][e]);
			}
		}
	}

	int ans = MAXDIST;
	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			ans = min(ans, cost[i][j] + cost[j][i]);

	if (ans == MAXDIST)
		ans = -1;
	cout << ans;

	return 0;
}