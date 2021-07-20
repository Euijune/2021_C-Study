#include <stdio.h>
#include <vector>
using namespace std;

void fibonacci(int n, vector<pair<int, int>>& num) {
    if (n == 0) {
        num[0] = { 1, 0 };
        return;
    }
    else if (n == 1) {
        num[1] = { 0, 1 };
        return;
    }
    else {
        if(num[n].first != 0) {
            return;
        }
        else {
        fibonacci(n - 2, num);
        fibonacci(n - 1, num);
        num[n].first = num[n - 2].first + num[n - 1].first;
        num[n].second = num[n - 2].second + num[n - 1].second;
        return;
        }
    }
}

int main() {
    int T, N, size;
    vector<pair<int, int>> num(1);

    size = 0;
    scanf_s("%d", &T);
    while (T) {
        scanf_s("%d", &N);
        if (N > size) {
            size = N+1;
            num.resize(size+3, { 0, 0 });
        }
        fibonacci(N, num);
        printf("%d %d\n", num[N].first, num[N].second);
        T--;
    }

    return 0;
}