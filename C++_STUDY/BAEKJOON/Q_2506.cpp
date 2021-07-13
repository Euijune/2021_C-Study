#include <stdio.h>

int main() {
	int n, x, score, ans;
	ans = 0;
	score = 1;
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &x);
		if (x) {
			ans += score;
			score++;
		}
		else {
			score = 1;
		}
	}

	printf("%d", ans);

	return 0;
}