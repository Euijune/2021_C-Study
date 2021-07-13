#include <stdio.h>
#include <stack>

int main() {
	int N, x , max;
	double sum, y, ans;
	std::stack<int> grade;
	max = 0;
	sum = 0;

	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &x);
		if (max < x) max = x;
		grade.push(x);
	}

	for (int i = 0; i < N; i++) {
		y = (grade.top() * 1.0 / max) * 100.0;
		grade.pop();
		sum += y;
	}

	ans = sum / N;
	printf("%f", ans);

	return 0;
}