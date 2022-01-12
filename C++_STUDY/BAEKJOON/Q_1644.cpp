#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int N, ans = 0;
vector<int> prime;

void DFS(int start) {
	int sum = 0;
	int SIZE = prime.size();

	if (start==SIZE)
		return;

	for (int i = start; i < SIZE; i++) {
		sum += prime[i];
		if (sum == N)
			ans++;
		if (sum > N)
			break;
	}

	DFS(start+1);
}

int main() {
	cin >> N;

	vector<int> prime_bin(N + 1, 1);

	prime_bin[0] = 0;
	prime_bin[1] = 1;

	// Sieve of Eratosthenes
	for (int i = 2; i <= sqrt(N); i++) {
		if (prime_bin[i] == 0)
			continue;

		for (int j = i * i; j <= N; j += i)
			prime_bin[j] = 0;
	}

	for (int i = 2; i <= N; i++)
		if (prime_bin[i] == 1)
			prime.push_back(i);

	DFS(0);
	cout << ans;

	return 0;
}