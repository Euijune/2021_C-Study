#include <stdio.h>

int* deciTobin(int n) {
	int num[30] = { 1,2,3, };
	return num;
}

void printArray(int* arr) {
	for (int i = 0; i < 30; i++) {
		printf("%d ", arr[i]);
	}
}

int main() {
	int N;
	int* Num;
	scanf_s("%d", &N);

	Num = deciTobin(N);
	printArray(Num);

	test; //test


	return 0;
}