#include <iostream>
#include <memory.h>
using namespace std;

int N;
bool find_min_ans = false;
bool find_max_ans = false;
char ineq_sign[9];
int ans[10];
bool used[10];

bool valid(int pre, int curr) {
	if (ineq_sign[curr - 1] == '<')
		return ans[pre] < ans[curr];
	else
		return ans[pre] > ans[curr];
}

void findMin(int curr) {
	if (find_min_ans)
		return;

	if (curr == N+1) {
		for (int i = 0; i <= N; i++)
			cout << ans[i];
		cout << endl;
		find_min_ans = true;
		return;
	}

	for (int i = 0; i <= 9; i++)
		if (!used[i]) {
			ans[curr] = i;
			used[i] = true;
			if (curr == 0)
				findMin(curr + 1);
			else if (curr >= 1 && valid(curr - 1, curr))
				findMin(curr + 1);
			used[i] = false;
		}
}

void findMax(int curr) {
	if (find_max_ans)
		return;

	if (curr == N + 1) {
		for (int i = 0; i <= N; i++)
			cout << ans[i];
		cout << endl;
		find_max_ans = true;
		return;
	}

	for (int i = 9; 0 <= i; i--)
		if (!used[i]) {
			ans[curr] = i;
			used[i] = true;
			if (curr == 0)
				findMax(curr + 1);
			else if (curr >= 1 && valid(curr - 1, curr))
				findMax(curr + 1);
			used[i] = false;
		}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++)
		cin>>ineq_sign[i];

	memset(ans, 0, sizeof(ans));
	memset(used, 0, sizeof(used));
	findMax(0);

	memset(ans, 0, sizeof(ans));
	memset(used, 0, sizeof(used));
	findMin(0);

	return 0;
}