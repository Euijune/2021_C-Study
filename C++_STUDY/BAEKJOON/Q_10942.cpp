#include <iostream>
#include <memory.h>
using namespace std;

#define MAXN 2000
#define endl '\n'

int N, M;
int seq[MAXN];
int cache[MAXN][MAXN];

int is_palindrome(int s, int e) {
	int& ret = cache[s][e];
	if (ret != -1)	return ret;

	ret = 1;

	for (int i = s, j = e; i <= (s+e)/2; i++, j--)
		if (seq[i] != seq[j]) {
			ret = 0;
			break;
		}

	if (ret == 1) {
		// if is_palindrome(i, j) == True, then is_palindrome(i+1, j-1) == True.
		for (int i = s + 1, j = e - 1; i <= (s + e) / 2; i++, j--)
			cache[i][j] = 1;

		// if is_palindrome(i, j) == True && seq[i-1] == seq[j+1], then is_palindrome(i-1, j+1) == True.
		for (int i = s - 1, j = e + 1; 0 <= i && j <= N - 1; i--, j++)
			if (seq[i] == seq[j])
				cache[i][j] = 1;
			else
				break;
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(cache, -1, sizeof(cache));

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> seq[i];

	cin >> M;

	for (int i = 0; i < M; i++) {
		int S, E;
		cin >> S >> E;

		cout << is_palindrome(S - 1, E - 1) << endl;
	}


	return 0;
}