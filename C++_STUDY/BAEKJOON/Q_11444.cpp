#include <iostream>
using namespace std;

/*
	idea: n번째 피보나치수는 (n/2-1)번째 피보나치 수[k1]와 (n/2)번째 피보나치 수[k2], 
	(n/2+1)번째 피보나치 수[k3], (n/2+2)번째 피보나치 수[k4]로 나타낼 수 있다.

	Ex) 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597 (n=17)
	k1 = 13
	k2 = 21
	k3 = 34
	k4 = 55
	987 = 13*21 + 21*34
	1597 = 13*34 + 21*55

	시간복잡도 : O(logn)
*/

#define R 1000000007
typedef long long ll;

pair<ll, ll> fibo(ll n) {	// n이 자연수일때 n-1, n번째 피보나치 수 반환
	if (n == 1)
		return { 0, 1 };

	pair<ll, ll> K = fibo(n / 2);
	ll k1 = K.first;
	ll k2 = K.second;
	ll k3 = (k1 + k2) % R;

	ll kn0, kn1;	// n-1번째 피보나치수, n번째 피보나치 수

	if (n % 2 == 0) {
		kn0 = (k1 * k1 % R + k2 * k2 % R) % R;
		kn1 = (k1 * k2 % R + k2 * k3 % R) % R;
	}
	else {
		ll k4 = (k2 + k3) % R;

		kn0 = (k1 * k2 % R + k2 * k3 % R) % R;
		kn1 = (k1 * k3 % R + k2 * k4 % R) % R;
	}
	return { kn0, kn1 };
}

int main() {
	long long n;
	cin >> n;

	cout<<fibo(n).second;

	return 0;
}