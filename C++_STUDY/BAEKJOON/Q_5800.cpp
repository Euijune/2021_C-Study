#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int K, N, classNum = 1;
	cin >> K;

	while (K--) {
		cin >> N;
		cout << "Class "<<classNum << endl;
		priority_queue <int, vector<int>, less<int>> Q;

		for (int i = 0; i < N; i++) {
			int tmp;
			cin >> tmp;
			Q.push(tmp);
		}

		int max = Q.top(), largest_gap = 0, size = Q.size();

		for (int i = 0; i < size-1; i++) {
			int n1 = Q.top();
			Q.pop();
			int n2 = Q.top();

			if (largest_gap < n1 - n2) {
				largest_gap = n1 - n2;
			}
		}

		int min = Q.top();

		cout << "Max " << max << ", Min " << min << ", Largest gap " << largest_gap << endl;
		classNum++;
	}

	return 0;
}