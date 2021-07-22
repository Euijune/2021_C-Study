#include <stdio.h>

int main() {
	int a, b, plus, sum, count;
	scanf_s("%d %d", &a, &b);

	sum = 0;
	plus = 0;
	count = 0;
	for (int i = 0; i < b; i++) {
		if (plus == count) {
			count = 0;
			plus++;
		}
		count++;
		if (i < a - 1)	continue;
		else			sum += plus;
	}

	printf("%d\n", sum);
	return 0;
}