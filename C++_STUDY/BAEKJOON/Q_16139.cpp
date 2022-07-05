#include <iostream>
#include <memory.h>
#include <string>
using namespace std;

#define MAXN 200000
#define endl '\n'

int pSum[MAXN][26];	// pSum[i][j] = i번째 문자까지 알파벳 숫자 , a = 0 & z = 26

void init(string s) {
	pSum[0][s[0] - 'a']++;

	for (int i = 1; i < s.length(); i++) {
		for (int j = 0; j < 26; j++)
			pSum[i][j] = pSum[i - 1][j];

		pSum[i][s[i] - 'a']++;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;

	init(str);

	int q;
	cin >> q;

	char input;
	int l, r;
	for (int i = 0; i < q; i++) {
		cin >> input >> l >> r;
		int indx = input - 'a';
		int p1 = pSum[r][indx];
		int p2 = l >= 1 ? pSum[l - 1][indx] : 0;
		cout << p1 - p2 << endl;
	}

	return 0;
}