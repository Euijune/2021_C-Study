#include <iostream>
#include <vector>
using namespace std;

int N, K, time = 0;
vector<int> visit(100001);

void move() {
	vector<int> temp(100001);

	for (int i = 1; i < 100000; i++)
		if (visit[i] == 1) {
			temp[i - 1] = 1;
			temp[i + 1] = 1;
			if (i <= 50000)
				temp[2 * i] = 1;
		}

	if (visit[0] == 1)
		temp[1] = 1;
	if (visit[100000] == 1)
		temp[99999] = 1;

	copy(temp.begin(), temp.end(), visit.begin());
	time++;
}

int main() {
	cin >> N >> K;

	if (N >= K)
		cout << N - K;
	else {
		visit[N] = 1;
		while (visit[K] != 1)
			move();

		cout << time;
	}

	return 0;
}