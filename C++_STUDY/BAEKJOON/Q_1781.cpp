#include <stdio.h>
#include <queue>
using namespace std;

class comp {
public:
	bool operator() (pair<int, int>& lhs, pair<int, int>& rhs) const {
		return lhs.second < rhs.second;
	}
};


int main() {

	priority_queue<pair<int, int>, vector<pair<int, int>>, comp> hw;
	int N, noodle, deadline, sum = 0, time = 0;
	scanf_s("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf_s("%d %d", &deadline, &noodle);
		hw.push({ deadline, noodle });
	}

	while (!hw.empty()) {
		if (hw.top().first > time) {
			sum += hw.top().second;
			printf("solve prob : %d %d\n", hw.top().first, hw.top().second);
			hw.pop();
			time++;
		}
		else {
			printf("erase : %d %d\n", hw.top().first, hw.top().second);
			hw.pop();

		}
	}

	printf("%d", sum);
	return 0;
}
// 알고리즘 더 생각해보자.
/*
반례
3
3 5
3 4
1 1
==> 10;
*/