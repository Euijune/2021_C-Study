#include <iostream>
using namespace std;

/*
	idea: n��° �Ǻ���ġ���� (n/2-1)��° �Ǻ���ġ ��[k1]�� (n/2)��° �Ǻ���ġ ��[k2], 
	(n/2+1)��° �Ǻ���ġ ��[k3], (n/2+2)��° �Ǻ���ġ ��[k4]�� ��Ÿ�� �� �ִ�.

	Ex) 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597 (n=17)
	k1 = 13
	k2 = 21
	k3 = 34
	k4 = 55
	987 = 13*21 + 21*34
	1597 = 13*34 + 21*55

	�ð����⵵ : O(logn)
*/

#define R 1000000007
typedef long long ll;

pair<ll, ll> fibo(ll n) {	// n�� �ڿ����϶� n-1, n��° �Ǻ���ġ �� ��ȯ
	if (n == 1)
		return { 0, 1 };

	pair<ll, ll> K = fibo(n / 2);
	ll k1 = K.first;
	ll k2 = K.second;
	ll k3 = (k1 + k2) % R;

	ll kn0, kn1;	// n-1��° �Ǻ���ġ��, n��° �Ǻ���ġ ��

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