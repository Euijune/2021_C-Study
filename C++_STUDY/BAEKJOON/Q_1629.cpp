#include <iostream>
using namespace std;

int	pow2(int A, int B, int C) {
	if (B == 1)	
		return A % C;
	
	long long k = pow2(A, B / 2, C);

	if (B % 2 == 0)
		return (k * k) % C;
	else
		return ((k * k) % C * (A % C)) % C;	
}

int main() {
	int A, B, C;
	cin >> A >> B >> C;

	cout<<pow2(A, B, C);

	return 0;
}