#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int A, B;
	scanf_s("%d %d", &A, &B); // M N ���¸� �Է¹޴� ���.
							  // ���� scanf_s("%d,&d", &A, &B); ��� M,N ���¸� �Է¹޴°���.
							// ���� �����Ϸ������� scanf_s�� �ƴ� scanf�Լ��� �ν��Ѵ�.

	cout << A + B;
	return 0;
}