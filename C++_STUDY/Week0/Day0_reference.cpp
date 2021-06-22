#include <iostream>
using namespace std;

void callbyVal(int a) {
	a = 20;
}

void callbyRef1(int* a) {
	*a = 20;
}

void callbyRef2(int& a) {
	a = 20;
}

int main() {
	int a = 10;
	int b = 10;
	int c = 10;
	int twenty = 20;

	callbyVal(a);
	callbyRef1(&b);
	callbyRef2(c);

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "c: " << c << endl;

	return 0;
}