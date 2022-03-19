#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N;
	cin >> T;

	while (T--) {
		int ans = 1;
		cin >> N;

		map<string, int> m;

		for (int i = 0; i < N; i++) {
			string name, kind;
			cin >> name >> kind;

			if (m.find(kind) != m.end())	// find
				m[kind]++;
			else
				m.insert({ kind, 1});
		}

		for (auto iter : m)
			ans = ans * (iter.second + 1);	// 해당 부위의 옷을 입지 않는 경우의 수까지 고려하여 경우의 수 계산

		ans--;	// 모든 옷을 입지 않는 경우 제외.
		cout << ans << endl;
	}

	return 0;
}