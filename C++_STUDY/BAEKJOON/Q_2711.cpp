#include <iostream>
#include <string>

using namespace std;

int main() {
	int T, indx;
	string str;
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		cin >> indx >> str;
		str = str.substr(0, indx - 1) + str.substr(indx);
		cout << str << endl;
	}

	return 0;
}