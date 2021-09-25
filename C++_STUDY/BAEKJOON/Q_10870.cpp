#include <iostream>
#include <vector>
using namespace std;

void printVec(vector<int>& vec) {
	for (auto elem : vec) {
		cout << elem << " ";
	}
	cout << endl;
}

int main() {
	int n;
	cin >> n;

	vector<int> vec;
	vec.push_back(0);
	vec.push_back(1);

	while (vec.size() <= n) {
		int n1 = vec[vec.size()-2];
		int n2 = vec[vec.size()-1];

		vec.push_back(n1 + n2);
		printVec(vec);
	}

	cout << vec[n];

	return 0;
}