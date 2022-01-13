#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int N, K, count = 0;
	cin >> N >> K;

	vector<int> prime(N + 1, 1);
	prime[0] = 0;
	prime[1] = 0;

	for (int i = 2; i <= N; i++) {
		if (prime[i] == 0)	continue;

		for (int j = i; j <= N; j+=i) {
			if (prime[j] == 0)	continue;
			prime[j] = 0;
			count++;
			if (count == K) {
				cout << j;
				exit(0);
			}
		}
	}


	return 0;
}