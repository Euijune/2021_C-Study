#include <stdio.h>
using namespace std;

int main() {
	int a1, a2, a3, a4, a5;
	int sum = 0;
	scanf_s("%d\n%d\n%d\n%d\n%d", &a1, &a2, &a3, &a4, &a5);
	sum = a1 + a2 + a3 + a4 + a5;
	printf("%d", sum);

	return 0;
}