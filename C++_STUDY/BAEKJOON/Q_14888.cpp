#include <iostream>
using namespace std;

int N;
int seq[11];
int oper[4];	// number of +, -, *, /
int ans_min = 1000000000, ans_max = -1000000000;

void calculate(int pre, int loc) {
	if (loc == N) {
		ans_min = min(ans_min, pre);
		ans_max = max(ans_max, pre);
		return;
	}

	int next;
	for (int i = 0; i < 4; i++)
		if (oper[i] > 0) {
			oper[i]--;
			if (i == 0)
				next = pre + seq[loc];
			else if (i == 1)
				next = pre - seq[loc];
			else if (i == 2)
				next = pre * seq[loc];
			else
				next = pre / seq[loc];

			calculate(next, loc + 1);
			oper[i]++;
		}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> seq[i];

	for (int i = 0; i < 4; i++)
		cin >> oper[i];

	calculate(seq[0], 1);

	cout << ans_max << '\n' << ans_min;

	return 0;
}