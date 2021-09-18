#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
}

int main() {
	vector<int> vec;

	for (int i = 0; i < 9; i++) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}

	int vecSize = vec.size();	
	printVector(vec);
	
	for (int i = 0; i < vecSize; i++) {
		for (int j = i+1; j < vecSize; j++) {
			vector<int>::iterator iter = vec.begin() + i;
			vector<int>::iterator iter2 = vec.begin() + j;
			vector<int> new_vec = vec;
			new_vec.erase(iter);
			new_vec.erase(iter2);

		}
	}

	return 0;
}