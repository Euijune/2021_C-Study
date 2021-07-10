#include <stdio.h>
#include <queue>

using namespace std;

int main() {
	int N;
	scanf_s("%d", &N);
	queue<int> q1; // Ã³À½ Ä«µåµ¦

	for (int i = 1; i <= N; i++) {
		q1.push(i);
	}

	//printf("test: %d, %d\n", q1.front(), q1.back());

	for (int i = 0; i < N-1; i++) {
		printf("%d ", q1.front());
		q1.pop();
		q1.push(q1.front());
		q1.pop();
	}
	printf("%d", q1.front());

	return 0;
}