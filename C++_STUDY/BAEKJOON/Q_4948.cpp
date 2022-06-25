#include <iostream>
#include <memory.h>
#include <cmath>
using namespace std;

#define LIMIT 246912
#define endl '\n'

bool primeNum[LIMIT+1];

void find_prime_num(int n) {
    for (int i = 2; i <= sqrt(2*n); i++)
    {
        // primeNum[i] �� 0�̸� �̹� �Ҽ��� �ƴϹǷ� continue
        if (primeNum[i] == false)
            continue;
        // i*k (k<i) ������ ���� �̹� �˻������Ƿ� j�� i*i ���� �˻����ش�.
        for (int j = i * i; j <= LIMIT; j += i)
            primeNum[j] = false;
    }
}

int count_prime_num(int n) {
    int cnt = 0;
    for (int i = n+1; i <= 2*n; i++)
        if (primeNum[i] == true)
            cnt++;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int n;
	cin >> n;

    // init array
    memset(primeNum, true, sizeof(bool) * (LIMIT + 1));

	while (n != 0) {
        find_prime_num(n);
        int ans = count_prime_num(n);
        cout << ans << endl;
		cin >> n;
	}

	return 0;
}