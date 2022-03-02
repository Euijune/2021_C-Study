#include <iostream>
#include <queue>
using namespace std;

#define endl '\n'

int tmp, N;
priority_queue<int, vector<int>, greater<int>> q_min;
priority_queue<int, vector<int>, less<int>> q_max;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> tmp;

		if (q_min.size() == q_max.size())
			q_max.push(tmp);
		else
			q_min.push(tmp);

		if (!q_max.empty() && !q_min.empty())
			if (q_max.top() > q_min.top()) {
				int MIN = q_min.top();
					int MAX = q_max.top();
					q_min.pop();
					q_max.pop();
					q_min.push(MAX);
					q_max.push(MIN);
			}

		cout << q_max.top() << endl;
	}

	return 0;
}