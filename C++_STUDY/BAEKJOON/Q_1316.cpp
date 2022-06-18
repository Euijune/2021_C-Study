#include <iostream>
#include <string>
using namespace std;

bool is_group_word(string w) {
	for (int i = 0; i < w.length(); i++) {

		// i��° ���ڿ� �����ϴ� ������ ���� Ž��
		int j = i + 1;
		while (w[i] == w[j])
			j++;

		// j��° ���ڴ� i��° ���ڿ� �ٸ� ù ��° �����̴�.
		// j+1��° ���ں���, i��° ���ڿ� ���� ���ڰ� ���´ٸ�, �� �ܾ�� �׷� �ܾ �ƴϴ�.
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