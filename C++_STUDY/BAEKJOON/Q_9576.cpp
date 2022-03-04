#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

typedef pair<int, int> pii;

class comp {
public:
	bool operator()(const pii& lhs, const pii& rhs)const {
		if (lhs.second == rhs.second)
			return lhs.first < rhs.first;
		return lhs.second > rhs.second;
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T, N, M;
	cin >> T;

	bool used[1001];
	priority_queue<pii, vector<pii>, comp> q;

	while (T--) {
		int ans = 0;
		cin >> N >> M;
		memset(used, false, sizeof(used));
		
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			q.push({ a,b });
		}

		while (!q.empty()) {
			pii book = q.top();
			for (int indx = book.first; indx <= book.second; indx++)
				if (!used[indx]) {
					used[indx] = true;
					ans++;
					break;
				}
			q.pop();
		}

		cout << ans << '\n';
	}
	

	return 0;
}