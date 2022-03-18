#include <iostream>
using namespace std;

int find_prime_factor(int n, int divisor) {
	int cnt = 0;
	while (n % divisor == 0) {
		n /= divisor;
		cnt++;
	}
	return cnt;
}

int find_zero_num(int n) {
	int zero_num;
	int cnt_factor_2 = 0, cnt_factor_5 = 0;
	for (int i = 1; i <= n; i++) {
		cnt_factor_2 += find_prime_factor(i,2);
		cnt_factor_5 += find_prime_factor(i,5);
	}
	zero_num = min(cnt_factor_2, cnt_factor_5);
	return zero_num;
}

int main() {
	int N;
	cin >> N;

	cout<<find_zero_num(N);

	return 0;
}