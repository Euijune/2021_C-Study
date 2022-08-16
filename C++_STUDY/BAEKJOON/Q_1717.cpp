#include <iostream>
#include <memory.h>
using namespace std;

#define MAXN 1000001
#define endl '\n'

int root[MAXN];
int RANK[MAXN];

int find(int x) {
	if (root[x] == x)
		return x;
	else
		return root[x] = find(root[x]);
}

void UNION(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b)
		return;

	if (RANK[a] < RANK[b])
		root[a] = b;
	else {
		root[b] = a;

		if (RANK[a] == RANK[b])
			RANK[a]++;
	}
}

void isSameSet(int a, int b) {
	if (find(a) == find(b))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; i++)
		root[i] = i;

	while (m--) {
		int cmd, a, b;
		cin >> cmd >> a >> b;

		if (cmd == 0)
			UNION(a, b);
		else 
			isSameSet(a, b);
	}

	return 0;
}