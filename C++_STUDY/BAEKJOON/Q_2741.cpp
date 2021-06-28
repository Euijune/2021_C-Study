#include <stdio.h>

int main() {
	int N;
	scanf_s("%d", &N);
	
	for (int i = 1; i < N + 1; i++) {
		printf("%d\n", i);
	}

	return 0;
}