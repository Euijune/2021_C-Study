#include <stdio.h>

void fibonacci(int m, int* num0, int* num1) {
    if (m > 1) {
        if (num0[m] != 0)   return;
        else {
            fibonacci(m - 2, num0, num1);
            fibonacci(m - 1, num0, num1);
            num0[m] = num0[m - 2] + num0[m - 1];
            num1[m] = num1[m - 2] + num1[m - 1];
        }

    }
}

int main() {
    int T, N;
    int numZero[43] = { 1,0, }, numOne[43] = { 0,1, };


    scanf("%d", &T);
    while (T) {
        scanf("%d", &N);
        fibonacci(N, numZero, numOne);
        printf("%d %d\n", numZero[N], numOne[N]);
        T--;
    }

    return 0;
}