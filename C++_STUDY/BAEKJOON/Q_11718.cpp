#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	char dlim = NULL;
	getline(cin, str, dlim); // getline(istream ��ü, string ���� �̸�, �ߴ���-delimitChar (defalut:\n))
	cout << str;

	return 0;
}