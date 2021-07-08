#include <stdio.h>
#include <stack>;
using namespace std;

int main() {
	int K, n, ans, temp;
	stack<int> sum;
	scanf_s("%d", &K);

	ans = 0;
	temp = 0;
	for (int i = 0; i < K; i++) {
		scanf_s("%d", &n);
		if (n == 0) {
			ans -= sum.top();
			sum.pop();
		}
		else {
			sum.push(n);
			ans += n;
		}
	}

	printf("%d", ans);

	return 0;
}