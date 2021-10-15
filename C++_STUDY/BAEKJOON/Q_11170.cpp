#include <iostream>
using namespace std;

void count_0(int n, int& ans){
	if (n == 0)	ans++;

	while (n != 0) {
		ans = (n % 10 == 0) ? ans + 1 : ans;
		n /= 10;
	}
};

int main()
{
	int T, N, M;

	cin >> T;
	for (int i = 0; i < T; ++i) {
		int ans = 0;
		cin >> N >> M;
		
		for (int j = N; j <= M; j++)
			count_0(j, ans);

		cout << ans << endl;
	}
	return 0;
}