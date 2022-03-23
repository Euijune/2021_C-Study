//참고 : https://st-lab.tistory.com/241

#include <iostream>
using namespace std;

#define ll long long
const int P = 1000000007;

ll pow(ll base, int expo) {
	ll res = 1;
	while (expo > 0) {
		if (expo % 2 == 1)
			res = (res * base) % P;
		base = (base * base) % P;
		expo /= 2;
	}
	return res;
}

ll factorial(int N) {
	ll res = 1;
	while (N) {
		res = (res * N) % P;
		N--;
	}
	return res;
}

int main() {
	int N, K;
	cin >> N >> K;
	
	// 분자 N!
	ll numer = factorial(N);
	
	// 분모 K!(N-K)! (mod P)
	ll denom = (factorial(K) * factorial(N - K)) % P;

	// 분자 * 분모의 역원
	cout << numer * pow(denom, P - 2) % P;

	return 0;
}