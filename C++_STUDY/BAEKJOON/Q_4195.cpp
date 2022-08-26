#include <iostream>
#include <sstream>
#include <map>
using namespace std;

#define MAXN 200000
#define endl '\n'

map<string, int> names;
int root[MAXN];
int RANK[MAXN];
int SIZE[MAXN];

class UnionFound {
private:
public:
	UnionFound(int F)
	{
		for (int i = 0; i < MAXN; i++) {
			root[i] = i;
			RANK[i] = 0;
			SIZE[i] = 1;
		}
	}
	int findRoot(int x);
	void UNION(string f1, string f2);
	void addNode(string a, string b);
	void printNetworkSize(string a, string b);
};

int UnionFound::findRoot(int x) {
	if (root[x] == x)
		return x;
	else
	{
		root[x] = findRoot(root[x]);
		SIZE[x] = SIZE[root[x]];
		return root[x];
	}
}

void UnionFound::UNION(string f1, string f2) {
	int a = findRoot(names[f1]);
	int b = findRoot(names[f2]);

	if (a == b)
		return;

	if (RANK[a] < RANK[b])
		root[a] = b;
	else {
		root[b] = a;
		if (RANK[a] == RANK[b])
			RANK[a]++;
	}
	
	SIZE[a] += SIZE[b];
	SIZE[b] = SIZE[a];
}

void UnionFound::addNode(string f1, string f2) {
	names.insert({ f1, names.size()});
	names.insert({ f2, names.size() });
	UNION(f1, f2);
}

void UnionFound::printNetworkSize(string a, string b) {
	cout << SIZE[findRoot(names[b])] << endl;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T--) {
		names.clear();
		int F;
		cin >> F;

		UnionFound f_network(F);
		for (int i = 0; i < F; i++) {
			string f1, f2;
			cin >> f1 >> f2;
			f_network.addNode(f1, f2);
			f_network.printNetworkSize(f1, f2);
		}
	}

	return 0;
}