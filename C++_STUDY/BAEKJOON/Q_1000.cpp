#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int A, B;
	scanf_s("%d %d", &A, &B); // M N 형태를 입력받는 경우.
							  // 만약 scanf_s("%d,&d", &A, &B); 라면 M,N 형태를 입력받는것임.
							// 백준 컴파일러에서는 scanf_s가 아닌 scanf함수를 인식한다.

	cout << A + B;
	return 0;
}