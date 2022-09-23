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
			N�� K�� ���� �ٲٸ�, solve���� temp�迭�� ����� �����ϰ�, �������� ����ϴ� ������ ���� �����ϴ�.
			�� �̸� ���� nextStep���� X*2�� �����̵��ϴ� ��츦 X/2�� �����̵� �ϴ� ���� �ٲ���� �Ѵ�.
			(���� �Ϸ�, ���� �� �ڵ�� 49421935�� �����ȣ Ȯ������.)
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