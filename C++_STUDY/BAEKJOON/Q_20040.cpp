#include <iostream>
#include <vector>
using namespace std;

#define MAXN 500000
int root[MAXN];
int RANK[MAXN];

class UnionFound {
private:
	int N;

	// Add variable
	int order;
	int first_make_cycle_order;
	bool is_have_cycle;

public:
	UnionFound(int n)
	{
		for (int i = 0; i <= n; i++) {
			root[i] = i;
			RANK[i] = 0;
		}
		N = n;
		order = 0;
		first_make_cycle_order = 0;
		is_have_cycle = false;
	}
	int find(int x);
	void UNION(int a, int b);
	
	// Add Function
	void isHaveCycle();
};

int UnionFound::find(int x) {
	if (root[x] == x)
		return x;
	else
		return root[x] = find(root[x]);
}

void UnionFound::UNION(int a, int b) {
	order++;
	a = find(a);
	b = find(b);

	if (a == b && !is_have_cycle)
	{
		is_have_cycle = true;
		first_make_cycle_order = order;
		return;
	}

	if (RANK[a] < RANK[b])
		root[a] = b;
	else {
		root[b] = a;

		if (RANK[a] == RANK[b])
			RANK[a]++;
	}
}

void UnionFound::isHaveCycle() {
	cout << first_make_cycle_order;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	UnionFound Set(N);

	for (int i = 0; i < M; i++) {
		int dot1, dot2;
		cin >> dot1 >> dot2;
		Set.UNION(dot1, dot2);
	}

	Set.isHaveCycle();		

	return 0;
}