#include <iostream>
using namespace std;

int sum2(int upto)
{
	if (upto == 1) {
		return 1;
	}
	else {
		return upto + sum2(upto - 1);
	}
}

int main() {
	cout << sum2(100);

	return 0;
}

