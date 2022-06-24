#include <iostream>
#include <vector>
#include <string>
using namespace std;

void swap(char& a, char& b) {
	char temp = a;
	a = b;
	b = temp;
}

int cut_board(int r, int c, vector<vector<string>>& board) {
	int cnt1 = 0, cnt2 = 0;
	string check1 = "W", check2 = "B";

	for (int i = r; i < r+8; i++) {
		for (int j = c; j < c+8; j++) {
			string temp = board[i][j];
			if (temp != check1)
				cnt1++;
			if (temp != check2)
				cnt2++;

			swap(check1, check2);
		}
		swap(check1, check2);
	}

	return min(cnt1, cnt2);
}

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<string>> board(N, vector<string>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char temp;
			cin >> temp;
			board[i][j] = temp;
		}
	}

	int ans = 64;

	for (int i = 0; i < N - 7; i++)
		for (int j = 0; j < M - 7; j++)
			ans = min(ans, cut_board(i, j, board));

	cout << ans;

	return 0;
}