#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> vec;

bool comp(const int& rhs, const int& lhs) {
	return lhs > rhs;	// 오름차순
}

int search_lowerIdx(int item, vector<int>& v);
int search_upperIdx(int item, vector<int>& v);

int main() {
	// For Fast I/O
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	

	cin >> N;
	int temp;
	while (N--) {
		cin >> temp;
		vec.push_back(temp);
	}

	sort(vec.begin(), vec.end(), comp);

	cin >> M;
	int lower_idx, upper_idx;
	while (M--) {
		cin >> temp;
		lower_idx = search_lowerIdx(temp, vec);
		upper_idx = search_upperIdx(temp, vec);
		cout << upper_idx - lower_idx << " ";
	}

	return 0;
}

int search_lowerIdx(int item, vector<int>& v) {
	int top = 0;
	int bot = v.size();

	while (top != bot) {
		int mid = (top + bot) / 2;
		if (v[mid] >= item)	bot = mid;
		else				top = mid + 1;
	}
	
	return top;
}

int search_upperIdx(int item, vector<int>& v) {
	int top = 0;
	int bot = v.size();

	while (top != bot) {
		int mid = (top + bot) / 2;
		if (v[mid] > item)	bot = mid;
		else				top = mid + 1;
	}

	return top;
}