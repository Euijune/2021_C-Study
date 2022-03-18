#include <iostream>
using namespace std;

int find_prime_factor(int n, int divisor) {
	/*
		from n!, calculate the number of divisor.
		Ex) 10!, divisor = 2 : return 8
	*/
	int cnt = 0;
	while (n) {
		n /= divisor;
		cnt += n;
	}
	return cnt;
}

int main() {
	int n, m, ans;
	cin >> n >> m;

	pair<int, int> numerator = { find_prime_factor(n, 2), find_prime_factor(n, 5) };
	pair<int, int> denominator = { find_prime_factor(n - m, 2) + find_prime_factor(m, 2),
									find_prime_factor(n - m, 5) + find_prime_factor(m, 5) };

	ans = min(numerator.first - denominator.first, numerator.second - denominator.second);

	cout << ans;

	return 0;
}