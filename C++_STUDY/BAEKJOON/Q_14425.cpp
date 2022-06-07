#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	unsigned int N, M;
	cin >> N >> M;

	unordered_set<string> S;

	while(N--) {
		string temp;
		cin >> temp;
		S.insert(temp);
	}

	int ans = 0;
	while(M--) {
		string item;
		cin >> item;
		if (S.find(item) != S.end())
			ans++;
	}

	cout << ans;

	return 0;
}