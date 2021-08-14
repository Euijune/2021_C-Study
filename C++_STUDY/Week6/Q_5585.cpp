#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, count = 0;
	vector<int> changelist = { 500, 100, 50, 10, 5, 1 };
	cin >> N;
	int change = 1000 - N;

	while (change) {
		if (change >= changelist[0]) {
			cout << change<<" "<<changelist[0] << endl;
			change -= changelist[0];
			count++;
		}
		else if (change < changelist[0]) {
			changelist.erase(changelist.begin());
		}
	}

	cout << count;

	return 0;
}