#include <stdio.h>
#include <math.h>

void Hanoi(int n, int from, int via, int to) {	// n���� ������ from(1)���� via(2)�� ���� to(3)���� �ű�� �Լ�
	if (n == 1) {
		printf("%d %d\n", from, to);
		return;
	}
	Hanoi(n - 1, from, to, via);	// n-1���� ������ from(1)���� to(3)�� ���� via(2)�� �ű�� �Լ�
	printf("%d %d\n", from, to);	// ���� ū ���� 1���� from(1)���� to(3)���� �ű�� �Լ�.
	Hanoi(n - 1, via, from, to);	// n-1���� ������ via(2)���� from(1)�� ���� to(3)���� �ű�� �Լ�
}

int main() {
	int N, K;
	scanf_s("%d", &N);
	
	K = pow(2, N) - 1;
	printf("%d\n", K);
	Hanoi(N, 1, 2, 3);
	return 0;
}