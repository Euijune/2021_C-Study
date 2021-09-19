#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;

	while (T--) {
		vector<int> vec;
		for (int i = 0; i < 5; i++) {
			int tmp;
			cin >> tmp;
			vec.push_back(tmp);
		}
		sort(vec.begin(), vec.end());

		vec.erase(vec.begin());
		vec.erase(vec.begin() + vec.size()-1);

		if (vec[2] - vec[0] >= 4) {
			cout << "KIN" << endl;
		}
		else {
			int sum = vec[0] + vec[1] + vec[2];
			cout << sum << endl;
		}
	}

	return 0;
}