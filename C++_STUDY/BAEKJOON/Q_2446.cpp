#include <iostream>
#include <string>

using namespace std;

string createStar(int i);
string createSpace(int i);

int main() {
	int n;
	string o = "";
	cin >> n;

	for (int i = 1; i <= n; i++){
		o = "";
		o.append(createSpace(i - 1));
		o.append(createStar(2 * (n - i) + 1));
		cout << o << endl;
	}
	for (int i = n-1; i >= 1; i--) {
		o = "";
		o.append(createSpace(i - 1));
		o.append(createStar(2 * (n - i) + 1));
		cout << o << endl;
	}

	return 0;
}

string createStar(int i) {
	string s = "";

	for (int j = 1; j <= i; j++) {
		s.append("*");
	}

	return s;
}

string createSpace(int i) {
	string s = "";

	for (int j = 1; j<=i; j++) {
		s.append(" ");
	}

	return s;
}