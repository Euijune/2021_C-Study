#include <iostream>
#include <vector>
#include <list>
using namespace std;

int N, K;
vector<int> visit(100001);

void move(int& time) {
	list<int> pre_visited;

	for (int i = 1; i < 100000; i++)
		if (visit[i] == 1)
			pre_visited.push_back(i);

	for (int indx : pre_visited) {
		visit[indx - 1] = 1;
		visit[indx + 1] = 1;
		if (indx <= 50000)
			visit[2 * indx] = 1;
	}

	if (visit[0] == 1)
		visit[1] = 1;
	if (visit[100000] == 1)
		visit[99999] = 1;

	time++;
}

int main() {
	int time = 0;
	cin >> N >> K;

	if (N >= K) {
		cout << N - K;
	}
	else {
		visit[N] = 1;

		/*cout << "time " << time << endl;
		for (int i = 0; i <= K; i++)
			cout << visit[i] << " ";
		cout << endl;*/

		while (visit[K] != 1) {
			move(time);

			/*cout << "time " << time << endl;
			for (int i = 0; i <= K; i++)
				cout << visit[i] << " ";
			cout << endl;*/
		}
		cout << time;
	}

	return 0;
}