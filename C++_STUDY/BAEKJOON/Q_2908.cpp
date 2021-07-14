#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, h_p, t_p, o_p;
	int _n[2];

	for (int i = 0; i < 2; i++) {
		cin >> n;
		h_p = n - n % 100;
		t_p = n % 100 - n % 10;
		o_p = n % 10;
		_n[i] = o_p * 100 + t_p + h_p / 100;
	}
	//A - A % 100 // 123 -> 100
	//A % 100 - A % 10 // 123 -> 20
	//A % 10 // 123 -> 3
	
	if (_n[0] > _n[1])	cout << _n[0];
	else				cout << _n[1];

	return 0;
}