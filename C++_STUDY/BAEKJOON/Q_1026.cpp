#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N, sum = 0;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> A;
	priority_queue<int, vector<int>, less<int>> B;
	
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		A.push(temp);
	}
	for (int i = 0; i < N; i++) {
		cin >> temp;
		B.push(temp);
	}

	while (!A.empty()) {
		int a = A.top();
		int b = B.top();

		sum += a * b;

		A.pop();
		B.pop();
	}

	cout << sum;
	return 0;
}