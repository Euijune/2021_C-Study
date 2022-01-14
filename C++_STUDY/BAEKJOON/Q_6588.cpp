#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define MAX 1000001
#define endl '\n'
vector<int> prime_bin(MAX, 1);

bool is_prime(int n) {
	return prime_bin[n];
}

int find_closer_prime(int n) {	// n보다 크지 않은 소수
	for (int index = n; index >= 0; index--)
		if (prime_bin[index])
			return index;
	return -1;
}

int main() {
	// For Fast I/O
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int closer_prime;

	prime_bin[0] = 0;
	prime_bin[1] = 1;

	// Sieve of Eratosthenes
	for (int i = 2; i <= sqrt(MAX); i++) {
		if (prime_bin[i] == 0)
			continue;

		for (int j = i * i; j <= MAX-1; j += i)
			prime_bin[j] = 0;
	}

	int n;
	do {
		bool find = false;
		cin >> n;
		if (n == 0)
			break;

		closer_prime = find_closer_prime(n - 3);
		while (closer_prime >= 3) {
			if (is_prime(n - closer_prime)) {
				cout << n << " = " << n - closer_prime << " + " << closer_prime << endl;
				find = true;
				break;
			}
			closer_prime = find_closer_prime(closer_prime - 1);
		}

		if (!find)
			cout << "Goldbach's conjecture is wrong." << endl;
		
	} while (n != 0);

	return 0;
}