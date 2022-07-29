#include <iostream>	
using namespace std;

#define INF 99999999
#define MAXN 100
#define endl '\n'

int cost[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i != j)
				cost[i][j] = INF;
		}

	for (int i = 0; i < m; i++) {
		int s, e, c;
		cin >> s >> e >> c;
		s--;
		e--;
		cost[s][e] = min(cost[s][e], c);
	}

	for (int node = 0; node < n; node++) {
		for (int s = 0; s < n; s++) {
			if (s == node)
				continue;
			for (int e = 0; e < n; e++) {
				if (e == node || s == e)
					continue;
				cost[s][e] = min(cost[s][e], cost[s][node] + cost[node][e]);
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (cost[i][j] == INF)
				cout << 0 << " ";
			else
				cout << cost[i][j] << " ";
		}
		cout << endl;
	}


	return 0;
}