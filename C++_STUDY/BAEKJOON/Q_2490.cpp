#include <stdio.h>

int main() {
	int n1, n2, n3, n4, sum;

	for (int i = 0; i < 3; i++) {
		sum = 0;
		scanf_s("%d %d %d %d", &n1, &n2, &n3, &n4);
		sum = n1 + n2 + n3 + n4;

		switch (sum) {
		case 0: // ��
			printf("%c\n", 'D');
			break;
		case 1: // ��
			printf("%c\n", 'C');
			break;
		case 2: // ��
			printf("%c\n", 'B');
			break;
		case 3: // ��
			printf("%c\n", 'A');
			break;
		case 4: // ��
			printf("%c\n", 'E');
			break;
		}
	}

	return 0;
}