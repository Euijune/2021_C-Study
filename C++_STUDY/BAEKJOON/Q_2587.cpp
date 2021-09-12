#include <iostream>
#include <queue>
using namespace std;

int main() {
	int sum = 0, avg = 0;
	priority_queue <int, vector<int>, greater<int>> Q;

	for (int i = 0; i < 5; i++) {
		int tmp;
		cin >> tmp;
		sum += tmp;
		Q.push(tmp);
	}
	avg = sum / 5;
	Q.pop();
	Q.pop();

	cout << avg << endl << Q.top();

	return 0;
}