#include <iostream>
using namespace std;

int main() {
	char numlist[101];
	cin >> numlist;

	for (char elem : numlist) {
		cout << elem << " ";
	}
	
	return 0;
}