#include <iostream>
#include <vector>
using namespace std;

int calculateSum(vector<int>& vec) {
	int sum = 0;
	for (int i = 0; i < vec.size(); i++) {
		sum += vec[i];
	}

	return sum;
}

int main() {
	vector<int> vec;
	for (int i = 0; i < 9; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
	
	int sum = 0;
	for (int i = 0; i < 8 && sum != 100; i++) {
		for (int j = i + 1; j < 9 && sum != 100; j++) {
			vector<int> vec2 = vec;
			vector<int>::iterator iter = vec2.begin() + i;
			vec2.erase(iter);
			vector<int>::iterator iter2 = vec2.begin() + j-1;
			vec2.erase(iter2);

			sum = calculateSum(vec2);
			if (sum == 100) {
				for (auto elem : vec2) {
					cout << elem << endl;
				}
			}	
		}
	}

	return 0;
}