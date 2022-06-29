#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector<int> intersection(set<int> v1, set<int> v2) {	// ±³ÁýÇÕ
	vector<int> buff(v1.size() + v2.size());
	auto iter = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), buff.begin());
	buff.erase(iter, buff.end());
	return buff;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int NA, NB;
	cin >> NA >> NB;

	set<int> A;
	set<int> B;

	for (int i = 0; i < NA; i++) {
		int elem;
		cin >> elem;
		A.insert(elem);
	}

	for (int i = 0; i < NB; i++) {
		int elem;
		cin >> elem;
		B.insert(elem);
	}

	vector<int> AnB = intersection(A, B);
	cout << NA + NB - AnB.size() * 2;


	return 0;
}