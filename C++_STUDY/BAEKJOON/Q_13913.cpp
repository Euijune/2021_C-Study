#include <iostream>
#include <vector>
using namespace std;

#define MAXN 100001
#define arr_time first
#define parent second

typedef pair<int, int> pii;	// <arr_time, parent>

int N, K;
vector<pii> visit(MAXN, { -1, -1 });

void nextStep(int i, int t) {
	if (i > 0 && visit[i - 1].arr_time == -1) {
		visit[i - 1].arr_time = t + 1;
		visit[i - 1].parent = i;
	}

	if (i < MAXN && visit[i + 1].arr_time == -1) {
		visit[i + 1].arr_time = t + 1;
		visit[i + 1].parent = i;
	}

	if (i % 2 == 0 && visit[i/2].arr_time == -1) {
		visit[i/2].arr_time = t + 1;
		visit[i/2].parent = i;
	}
}

void move(int& t) {
	for (int i = 1; i < MAXN; i++)
		if (visit[i].arr_time == t)
			nextStep(i, t);
	t++;
}

void solve(int& t) {
	vector<int> temp(t + 1, 0);
	int curr = K;

	cout << t << endl;
	for (int i = 0; i < t; i++) {
		cout << curr << " ";
		curr = visit[curr].parent;
	}
	cout << curr;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	if (N < K) {
		/*
			N과 K를 서로 바꾸면, solve에서 temp배열을 만들어 저장하고, 역순으로 출력하는 과정을 생략 가능하다.
			단 이를 위해 nextStep에서 X*2로 순간이동하는 경우를 X/2로 순간이동 하는 경우로 바꿔줘야 한다.
			(수정 완료, 수정 전 코드는 49421935번 제출번호 확인하자.)
		*/
		int tmp = N;
		N = K;
		K = tmp;

		int t = 0;
		visit[N] = { t,N };

		while (visit[K].arr_time == -1)
			move(t);

		solve(t);
	}
	else {
		int t = N - K;

		cout << t << endl;
		for (int i = N; i >= K; i--)
			cout << i << " ";
	}


	return 0;
}