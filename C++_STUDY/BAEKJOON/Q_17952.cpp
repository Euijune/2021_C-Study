#include <stdio.h>
#include <stack>

using pii = std::pair<int, int>;

int main() {
	int N, score, reqTime, ans, isHw;
	std::stack<pii> hw;
	scanf_s("%d", &N);

	ans = 0;
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &isHw); // isHw는 0 또는 1의 값만 가진다.

		if (isHw) { // 과제가 있을 때
			scanf_s("%d %d", &score, &reqTime);
			hw.push({ score, reqTime }); // 과제를 받으면 hw stack에 추가한다.
			hw.top().second--; // 과제를 받은 시점부터 풀기 시작했으므로 reqTime을 감소.
			
			printf("test : %d\n", hw.top().second); //test
		}
		else { // 과제가 없을때
			if (hw.empty()) continue; // hw가 비어있을때 isHw = 0인 경우 예외처리
			else hw.top().second -= 1; // hw = 0 이더라도 이전에 받은 과제를 이어서 해결

			printf("test : %d\n", hw.top().second); //test
		}

		if (hw.top().second == 0) { // 다 푼 문제 발생 (reqTime = 0)
			ans += hw.top().first;

			printf("ans test : %d\n", ans); //test

			hw.pop();
		}
	}
	printf("%d", ans);

	return 0;
}