#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define COD_BEGIN coordinate_compressed.begin()
#define COD_END coordinate_compressed.end()

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> save_order;
	vector<int> coordinate_compressed;
	save_order.resize(N);
	coordinate_compressed.resize(N);

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		save_order[i] = tmp;
		coordinate_compressed[i] = tmp;
	}

	sort(COD_BEGIN, COD_END);
	coordinate_compressed.erase(unique(COD_BEGIN, COD_END), COD_END);

	for (int& elem : save_order)
		cout << lower_bound(COD_BEGIN, COD_END, elem) - COD_BEGIN << " ";

	return 0;
}