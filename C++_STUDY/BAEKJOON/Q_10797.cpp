#include <iostream>

using namespace std;

int main() {
	int day, car, ans;
	ans = 0;
	cin >> day;

	for (int i = 0; i < 5; i++) {
		cin >> car;
		if (car == day)
			ans++;
	}
	cout << ans;

}