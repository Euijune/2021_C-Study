#include <iostream>
#include <stack>
using namespace std;

bool isVps(string& ps) {
	int cnt = 0;
	for (int i = 0; i < ps.size(); i++) {
		if (ps[i] == '(')
			cnt++;
		else
			cnt--;
		if (cnt < 0)
			return false;
	}
	return cnt == 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	string ps;
	while (T--) {
		cin >> ps;

		bool is_vps = isVps(ps);

		if (is_vps)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}