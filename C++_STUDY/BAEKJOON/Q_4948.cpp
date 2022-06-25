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
        // primeNum[i] 가 0이면 이미 소수가 아니므로 continue
        if (primeNum[i] == false)
            continue;
        // i*k (k<i) 까지의 수는 이미 검사했으므로 j는 i*i 부터 검사해준다.
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