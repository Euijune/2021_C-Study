#include <iostream>
using namespace std;

#define MAXN 1024
#define endl '\n'

int nums[MAXN];		// nums[i]: 1행 1열부터 i행 N-1열까지의 누적 합
int nums_col[MAXN][MAXN];		// nums_col[i][j] : 1행 j열 부터 i행 j열까지의 누적 합

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int input;
			cin >> input;

			if (i > 0 && j == 0)
				nums[i] = nums[i - 1];
			nums[i] += input;

			if (i == 0)
				nums_col[0][j] = input;
			else
				nums_col[i][j] = nums_col[i - 1][j] + input;
		}
	}

	for (int i = 0; i < M; i++) {
		int ans = 0;
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		// index
		x1--;
		y1--;
		x2--;
		y2--;

		int p1 = nums[x2];
		int p2;

		if (x1 == 0)
			p2 = 0;
		else
			p2 = nums[x1-1];

		ans = p1 - p2;

		for (int c = 0; c < N; c++) {
			if (y1 <= c && c <= y2)
				continue;

			int p1_col = nums_col[x2][c];
			int p2_col = x1 > 0 ? nums_col[x1 - 1][c] : 0;

			ans -= (p1_col - p2_col);
		}

		cout << ans << endl;
	}


	return 0;
}