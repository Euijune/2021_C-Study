#include <iostream>
#include <memory.h>
#include <cmath>
using namespace std;

#define MAX_N 10000000
#define SIZE 4000
#define endl '\n'

bool is_prime[SIZE];

int find_primes(int N){
	for (int i = 2; i <= sqrt(N) + 2; i++)
		if (is_prime[i])
			for (int j = i * i; j <= sqrt(N) + 2; j += i)
				is_prime[j] = false;
	
	return sqrt(N) + 3;
}

void prime_factorization(int limit, int N) {
	for (int i = 2; i < limit; i++) {
		if (N % i == 0)
			while (N % i == 0) {
				cout << i << endl;
				N /= i;
			}

		limit = min(limit, N);
	}
	if (N != 1)	// 贸澜何磐 N捞 家荐老 版快
		cout << N;
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);

	int N;
	cin >> N;

	if (N == 1)
		return 0;

	memset(is_prime, true, sizeof(bool) * SIZE);
	is_prime[0] = false;
	is_prime[1] = false;

	int limit = find_primes(N);
	prime_factorization(limit, N);

	return 0;
}