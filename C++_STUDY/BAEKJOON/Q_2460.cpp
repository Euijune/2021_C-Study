#include <stdio.h>

int main() {
	int ride, quit, train, max;
	train = 0;
	max = 0;

	for (int i = 0; i < 10; i++) {
		scanf_s("%d %d", &quit, &ride);
		train -= quit;
		train += ride;
		if (train > max) max = train;
	}
	printf("%d", max);

	return 0;
}