#include <stdio.h>

using namespace std;

int main() {
	int T, N, x, sum;
	scanf_s("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf_s("%d", &N);
		sum = 0;

		for (int j = 0; j < N; j++) {
			scanf_s("%d", &x);
			sum += x;
		}

		printf("%d\n", sum);
	}

	return 0;
}