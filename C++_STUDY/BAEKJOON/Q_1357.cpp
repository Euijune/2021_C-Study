#include <iostream>
using namespace std;

int Rev(int x);

int main() {
	int x, y, x_rev, y_rev, ans;
	cin >> x >> y;

	x_rev = Rev(x);
	y_rev = Rev(y);

	cout << "test:: " << x_rev << " " << y_rev << endl;

	ans = Rev(x_rev + y_rev);
	cout << ans;

	return 0;
}

int Rev(int x) {
	cout << "input:: " << x << endl;
	int x_new; 

	if (0 < x && x < 10) {
		x_new = x;

		return x_new;
	}
	else if (10 <= x  && x < 100) {
		int units, tens;
		units = x % 10;
		tens = (x - units) / 10;

		x_new = units * 10 + tens;

		return x_new;
	}
	else if (100 <= x && x < 1000){
		int units, tens, hundreds;
		units = (x % 100) % 10;
		tens = ((x % 100) - units) / 10;
		hundreds = (x - (tens * 10 + units)) / 100;

		x_new = units * 100 + tens * 10 + hundreds;

		return x_new;
	}
	else {
		int units, tens, hundreds, thousands;
		units = ((x % 1000) % 100) % 10;
		tens = (((x % 1000) % 100) - units) / 10;
		hundreds = (x % 1000 - (tens * 10 + units)) / 100;
		thousands = (x - (hundreds * 100 + tens * 10 + units)) / 1000;

		cout << "test:: " << thousands << " " << hundreds << " " << tens << " " << units << endl;

		x_new = units * 1000 + tens * 100 + hundreds * 10 + thousands;

		return x_new;
	}
}