#include <stdio.h>
#include <math.h>

void Hanoi(int n, int from, int via, int to) {	// n개의 원판을 from(1)에서 via(2)를 거쳐 to(3)으로 옮기는 함수
	if (n == 1) {
		printf("%d %d\n", from, to);
		return;
	}
	Hanoi(n - 1, from, to, via);	// n-1개의 원판을 from(1)에서 to(3)을 거쳐 via(2)로 옮기는 함수
	printf("%d %d\n", from, to);	// 가장 큰 원판 1개를 from(1)에서 to(3)으로 옮기는 함수.
	Hanoi(n - 1, via, from, to);	// n-1개의 원판을 via(2)에서 from(1)을 거쳐 to(3)으로 옮기는 함수
}

int main() {
	int N, K;
	scanf_s("%d", &N);
	
	K = pow(2, N) - 1;
	printf("%d\n", K);
	Hanoi(N, 1, 2, 3);
	return 0;
}