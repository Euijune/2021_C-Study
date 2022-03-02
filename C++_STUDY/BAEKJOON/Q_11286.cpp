#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

#define endl '\n'

class comp {
public:
	bool operator()(const int& left, const int& right) const {
		if (abs(left) == abs(right))
			return left > right;
		else
			return abs(left) > abs(right); // 오름차순
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	priority_queue<int, vector<int>, comp> arr;
	int N, cmd;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> cmd;
		if (cmd == 0)
			if (arr.empty())
				cout << 0 << endl;
			else {
				cout << arr.top() << endl;
				arr.pop();
			}
		else
			arr.push(cmd);
	}

	return 0;
}