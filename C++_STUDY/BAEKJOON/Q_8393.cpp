#include <stdio.h>

using namespace std;

int main() {
	int n;
	scanf_s("%d", &n);

	printf("%d", n * (n + 1) / 2);

	return 0;
}