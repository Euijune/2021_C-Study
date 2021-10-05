#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int T;
	cin >> T;
	cin.ignore();

	while (T--) {
		getline(cin, s);
		s[0] = (s[0] < 97) ? s[0] : s[0] - 32;
		cout << s << endl;
	}

	return 0;
}