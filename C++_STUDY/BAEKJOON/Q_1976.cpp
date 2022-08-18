#include <iostream>
#include <vector>
using namespace std;

#define MAXN 200

class UnionFound {
private:
	int N;
	int root[MAXN];
	int rank[MAXN];

	// Add variable
	int M;
public:
	UnionFound(int n, int m)
	{
		for (int i = 0; i <= n; i++) {
			root[i] = i;
			rank[i] = 0;
		}
		N = n;
		M = m;
	}
	int find(int x);
	void UNION(int a, int b);
	void addNode(int start_node, vector<int> info);

	// Add Function
	void checkPlan(vector<int> plan);
};

int UnionFound::find(int x) {
	if (root[x] == x)
		return x;
	else
		return root[x] = find(root[x]);
}

void UnionFound::UNION(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b)
		return;

	if (rank[a] < rank[b])
		root[a] = b;
	else {
		root[b] = a;

		if (rank[a] == rank[b])
			rank[a]++;
	}
}

void UnionFound::addNode(int start_node, vector<int> info) {
	for (int end_node = 0; end_node < N; end_node++)
		if (info[end_node] == 1)
			UNION(start_node, end_node);
}

void UnionFound::checkPlan(vector<int> plan) {
	bool is_possible = true;
	for (int i = 0; i < M - 1; i++) {
		int city1 = plan[i];
		int city2 = plan[i + 1];

		if (find(city1) != find(city2)) {	// city1 and city2 are not connected.
			is_possible = false;
			break;
		}
	}
	if (is_possible)
		cout << "YES";
	else
		cout << "NO";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	UnionFound Set(N, M);

	for (int i = 0; i < N; i++) {
		vector<int> info;
		for (int j = 0; j < N; j++) {
			int connect;
			cin >> connect;
			info.push_back(connect);
		}
		Set.addNode(i, info);
	}

	// Travel Plan
	vector<int> plan;
	for (int i = 0; i < M; i++) {
		int city_num;
		cin >> city_num;
		plan.push_back(city_num - 1);	// 1 ~ N ==> 0 ~ N-1
	}

	Set.checkPlan(plan);

	return 0;
}