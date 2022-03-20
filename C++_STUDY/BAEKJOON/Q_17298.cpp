#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	vector<int> seq;
	stack<int> s;
	stack<int> ans;

	int N, curr;
	cin >> N;
	seq.resize(N);

	for (int i = 0; i < N; i++)
		cin >> seq[i];

	for (int i = N - 1; 0 <= i; i--) {
		if (s.empty())
			ans.push(-1);
		else {
			while (!s.empty() && s.top() <= seq[i])
				s.pop();

			if (!s.empty())
				ans.push(s.top());
			else
				ans.push(-1);
		}
		s.push(seq[i]);
	}

	while (!ans.empty()) {
		cout << ans.top() << " ";
		ans.pop();
	}
	
	return 0;
}