#include <stdio.h>
#include <vector>
using namespace std;

int Energy(vector<int> w, int N) {
	int max = 0;
	int temp = 0;

	if (N == 3) {
		return w[0] * w[2];
	}
	else {
		for (int i = 1; i < N - 1; i++) {	// 첫번째와 마지막 구슬은 선택 불가
			vector<int> new_w = w;
			new_w.erase(new_w.begin() + i);
			temp = Energy(new_w, N - 1) + w[i - 1] * w[i + 1];

			if (max < temp) {
				max = temp;
			}
		}
		return max ;
	}
}

int main() {
	int N, ans;
	scanf_s("%d", &N);
	vector<int> w(N);

	ans = 0;
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &w[i]);
	}

	ans = Energy(w, N);
	printf("%d", ans);

	return 0;
}