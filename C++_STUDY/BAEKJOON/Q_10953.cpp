#include <stdio.h>
using namespace std;

int main() {
	int A, B, T;
	scanf_s("%d", &T);

	while (T--) {
		scanf_s("%d, %d", &A, &B);
		printf("%d\n", A + B);
	}

	return 0;
}