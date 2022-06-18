#include <iostream>
#include <string>
using namespace std;

bool is_group_word(string w) {
	for (int i = 0; i < w.length(); i++) {

		// i번째 글자와 연속하는 글자의 범위 탐색
		int j = i + 1;
		while (w[i] == w[j])
			j++;

		// j번째 글자는 i번째 글자와 다른 첫 번째 글자이다.
		// j+1번째 글자부터, i번째 글자와 같은 글자가 나온다면, 이 단어는 그룹 단어가 아니다.
		for (int k = j+1; k < w.length(); k++)
			if (w[i] == w[k])
				return false;

		i = j - 1;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, ans = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string word;
		cin >> word;
		if (is_group_word(word))
			ans++;
	}

	cout << ans;

	return 0;
}