#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, ans = 0, sum = 0;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> decks;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		decks.push(temp);
	}

	int d1, d2;
	while (decks.size() > 1) {
		d1 = decks.top();
		decks.pop();
		d2 = decks.top();
		decks.pop();

		sum = d1 + d2;
		ans += sum;
		decks.push(sum);
	}
	cout << ans;
	exit(0);

	return 0;
}