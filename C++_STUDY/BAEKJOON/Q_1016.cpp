#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define ll long long

int main() {
	ll MIN, MAX;
	int MAX_sqrt, SIZE, ANS;

	cin >> MIN >> MAX;

	MAX_sqrt = sqrt(MAX);
	SIZE = MAX - MIN + 1;
	ANS = SIZE;

	vector <int> nono(SIZE, 1);

	for (ll i = 2; i <= MAX_sqrt; i++) {
		ll temp = MIN % (i*i) == 0 ? MIN / (i * i) : MIN / (i*i) + 1;	// Ex : MIN = 100; i = 4인 경우와 MIN = 100; i=5인 경우 비교.
		for (ll j = i*i*temp; j <= MAX; j += i * i) {
			if (nono[j - MIN] == 1) {
				nono[j - MIN] = 0;
				ANS--;
			}
		}
	}
	cout << ANS;

	return 0;
}