#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	char dlim = NULL;
	getline(cin, str, dlim); // getline(istream 객체, string 변수 이름, 중단자-delimitChar (defalut:\n))
	cout << str;

	return 0;
}