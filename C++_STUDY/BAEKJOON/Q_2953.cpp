#include <iostream>

using namespace std;

int main() {
	int score, sum, max, ans;

	max = 0;
	ans = 0;
	for (int i = 1; i <= 5; i++) {
		sum = 0;
		for (int j = 0; j < 4; j++) {
			cin >> score;
			sum += score;
		}
		if (max < sum) {
			max = sum;
			ans = i;
		}
	}

	cout << ans << '\n' << max;
	
	return 0;
}