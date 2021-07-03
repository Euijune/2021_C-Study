#include <stdio.h>
using namespace std;

int main() {
	int N, M, sum;
	scanf_s("%d", &N);

	sum = 0;
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &M);
		sum += M;
	}

	sum -= N - 1;
	printf("%d", sum);
	
	return 0;
}