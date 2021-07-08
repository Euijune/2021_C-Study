#include <stdio.h>
#include <stack>

using pii = std::pair<int, int>;

int main() {
	int N, score, reqTime, ans, isHw;
	std::stack<pii> hw;
	scanf_s("%d", &N);

	ans = 0;
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &isHw); // isHw�� 0 �Ǵ� 1�� ���� ������.

		if (isHw) { // ������ ���� ��
			scanf_s("%d %d", &score, &reqTime);
			hw.push({ score, reqTime }); // ������ ������ hw stack�� �߰��Ѵ�.
			hw.top().second--; // ������ ���� �������� Ǯ�� ���������Ƿ� reqTime�� ����.
			
			printf("test : %d\n", hw.top().second); //test
		}
		else { // ������ ������
			if (hw.empty()) continue; // hw�� ��������� isHw = 0�� ��� ����ó��
			else hw.top().second -= 1; // hw = 0 �̴��� ������ ���� ������ �̾ �ذ�

			printf("test : %d\n", hw.top().second); //test
		}

		if (hw.top().second == 0) { // �� Ǭ ���� �߻� (reqTime = 0)
			ans += hw.top().first;

			printf("ans test : %d\n", ans); //test

			hw.pop();
		}
	}
	printf("%d", ans);

	return 0;
}