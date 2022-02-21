#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

class cmp {
public:
	bool operator()(const pii& lhs, const pii& rhs)const {
		if (lhs.second == rhs.second)
			return lhs.first > rhs.first;
		else
			return lhs.second > rhs.second;
	}
};

priority_queue<pii, vector<pii>, cmp> conf;

int main() {
	int N, ans = 0, curr = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp1, tmp2;
		cin >> tmp1>> tmp2;
		conf.push({ tmp1, tmp2 });
	}

	for (int i = 0; i < N; i++) {
		pii conference = conf.top();
		conf.pop();
		if (conference.first >= curr) {
			curr = conference.second;
			ans++;
		}
	}

	cout << ans;

	return 0;
}