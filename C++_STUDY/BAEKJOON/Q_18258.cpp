#include <iostream>
#include <string>
#include <list>
using namespace std;

#define endl '\n'

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	list<int> q;

	while (N--) {
		string cmd;
		cin >> cmd;

		if (cmd == "push") {
			int elem;
			cin >> elem;
			q.push_back(elem);
		}
		else if (cmd == "pop")
			if (!q.empty()) {
				cout << q.front() << endl;
				q.pop_front();
			}
			else
				cout << -1 << endl;
		else if (cmd == "size")
			cout << q.size() << endl;
		else if (cmd == "empty")
			cout << q.empty() << endl;
		else if (cmd == "front")
			if (!q.empty())
				cout << q.front() << endl;
			else
				cout << -1 << endl;
		else
			if (!q.empty())
				cout << q.back() << endl;
			else
				cout << -1 << endl;
	}

	return 0;
}