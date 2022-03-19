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
			ans = ans * (iter.second + 1);	// �ش� ������ ���� ���� �ʴ� ����� ������ ����Ͽ� ����� �� ���

		ans--;	// ��� ���� ���� �ʴ� ��� ����.
		cout << ans << endl;
	}

	return 0;
}