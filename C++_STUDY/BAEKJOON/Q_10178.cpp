#include <stdio.h>
using namespace std;

int main() {
	int testcase, candy, brother;
	scanf_s("%d", &testcase);
	
	for (int i = 0; i < testcase; i++) {
		scanf_s("%d %d", &candy, &brother);
		printf("You get %d piece(s) and your dad gets %d piece(s).\n", candy / brother, candy % brother);
	}

	return 0;
}