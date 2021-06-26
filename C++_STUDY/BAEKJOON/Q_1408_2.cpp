// 이전에 제출한 알고리즘을 개선하였습니다.
#include<stdio.h>

int main(void) {
	int startH, startM, startS, currentH, currentM, currentS;
	scanf_s("%d:%d:%d", &currentH, &currentM, &currentS);
	scanf_s("%d:%d:%d", &startH, &startM, &startS);

	if (currentS > startS) {
		startS += 60;
		startM--;
	}
	if (currentM > startM) {
		startM += 60;
		startH--;
	}
	if (currentH > startH) {
		startH += 24;
	}

	printf("%02d:%02d:%02d", startH - currentH, startM - currentM, startS - currentS);

	return 0;
}