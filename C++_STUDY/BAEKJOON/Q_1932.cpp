#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> triangle;


int main() {
	// For Fast I/O
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, ans, temp, pre_max;
	ans = 0;
	pre_max = 0;
	cin >> N;
	
	triangle.resize(N);

	// 첫번째 줄
	triangle[0].resize(1);
	cin >> triangle[0][0];

	// 두번째 줄부터
	for (int i = 1; i < N; i++) {
		triangle[i].resize(i + 1);
		for (int j = 0; j < i + 1; j++) {
			cin >> temp;
			if (j == 0)
				pre_max = triangle[i - 1][j];
			else if (j == i)
				pre_max = triangle[i - 1][j - 1];
			else
				pre_max = max(triangle[i-1][j], triangle[i-1][j-1]);
			triangle[i][j] = temp + pre_max;
		}
	}

	for (int elem : triangle[N - 1])
		ans = max(ans, elem);

	cout << ans;

	return 0;
}