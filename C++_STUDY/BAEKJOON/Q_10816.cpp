#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool comp (const int& rhs, const int& lhs) {
	return lhs > rhs;	// 오름차순
}

int search(int item, vector<int> v);


int main() {
	int N, M;
	vector<int> vec;

	cin >> N;
	int temp;
	while (N--) {
		cin >> temp;
		vec.push_back(temp);
	}

	sort(vec.begin(), vec.end(), comp);
	cout << vec.size();

	cin >> M;
	while (M--) {
		cin >> temp;
	}

	return 0;
}

int search(int item, vector<int> v) {
	int index = 0;
	int top = 0;
	int bot = v.size();

	return index;
}