#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 30

int w1[MAXN/2];
int w2[MAXN/2];
vector<long long> subset1;
vector<long long> subset2;

void makeSubset(vector<long long>& subset, int num, int SIZE, int mode) {
	vector<bool> v(SIZE - num, false);
	v.insert(v.end(), num, true);
	do {
		long long sum = 0;
		for (int i = 0; i < SIZE; i++)
			if (v[i] && mode == 1)
				sum += w1[i];
			else if (v[i] && mode == 2)
				sum += w2[i];
		subset.push_back(sum);	
	} while (next_permutation(v.begin(), v.end()));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, W;
	cin >> N >> W;

	int half = ceil((double)N / 2);
	for (int i = 0; i < N; i++)
		if (i < half)
			cin >> w1[i];
		else
			cin >> w2[i - half];


	for (int num = 0; num <= ceil((double)N/2); num++)
		makeSubset(subset1, num, ceil((double)N/2), 1);

	for (int num = 0; num <= floor((double)N/2); num++)
		makeSubset(subset2, num, floor((double)N/2), 2);

	sort(subset1.begin(), subset1.end());

	int ans = 0;	
	for (long long elem2 : subset2) {
		if (elem2 > W)
			continue;

		int left = 0;
		int right = size(subset1);

		while (left < right) {
			int mid = floor((double)(left + right) / 2);
			if (elem2 + subset1[mid] > W)
				right = mid;
			else
				left = mid + 1;
		}

		ans += right;
	}
	cout << ans;
	
	return 0;
}