#include <stdio.h>
#include <queue>

using namespace std;
using pii = pair<int, int>;

void move(pii* apple, queue<pii>& snake, int& row, int& col, char dir, int K); // ���� �̵� ����
bool isApple(pii* apple, int row, int col, int K); // ����� �����°�?
void changeDirection(char& dir, char cmd);
bool isHitWall(queue<pii> snake, int N);
bool isHitBody(); // �����ؾ� ��
//bool gameOver(isHitWall(), isHitBody()); // ����


int main() {
	int N, K, L, row, col, t, time = 0;
	char cmd, direction = 'R'; // Left, Right, Up, Down. �ʱ� ������ ��������

	queue<pii> snake({ {1,1} });	// ���� ���� ���� ����. front�� ����, back�� �Ӹ�.
	printf("�ʱ���ġ : %d�� %d��\n", snake.back().first, snake.back().second); // test
	queue<pii> dire;	//���� ��ȯ�� ���� ����

	scanf_s("%d", &N);

	// ��� ��ġ ����
	scanf_s("%d", &K);
	pii* apple = new pii[K];	// ��� ��ġ ����

	for (int i = 0; i < K; i++) {
		scanf_s("%d %d", &row, &col);
		apple[i] = { row, col };
	}

	
	// ���� ��ȯ���� ����
	scanf_s("%d", &L);
	for (int i = 0; i < L; i++) {
		scanf_s("%d %c", &t, &cmd, 1);
		dire.push({ t, cmd });
	}
	
	while (!isHitWall(snake, N)) {
		time++;	//�� �ʸ���
		printf("====== time = %d ======\n\n", time);
		move(apple, snake, snake.front().first, snake.front().second, direction, K);	// �־��� ���ǿ� ���� �̵��Ѵ�. move(queue, row, col, dir)
		
		if (time == dire.front().first) { // ������ȯ
			printf("������ȯ : %c\n", dire.front().second);	//test
			changeDirection(direction, dire.front().second);
			dire.pop();
		}
	}
	printf("\nAnswer : %d", time);

	delete[] apple;
	return 0;
}

void move(pii* apple, queue<pii>& snake, int& row, int& col, char dir, int K) {
	int new_r = 0, new_c = 0;

	switch (dir) {
	case 'L':
		new_r = row - 1;
		new_c = col;
		break;
	case 'R':
		new_r = row + 1;
		new_c = col;
		break;
	case 'D':
		new_r = row;
		new_c = col + 1;
		break;
	case 'U':
		new_r = row;
		new_c = col - 1;
		break;
	}

	if (isApple(apple, row, col, K)) {	//�̵��� ĭ�� ����� ���� ���
		snake.push({ new_r, new_c });
		printf("�Ӹ� : %d�� %d��\n", snake.back().first, snake.back().second); // test
		printf("���� : %d�� %d��\n", snake.front().first, snake.front().second); // test
	}
	else {				// �̵��� ĭ�� ����� ���� ���
		snake.push({ new_r, new_c });
		snake.pop();
		printf("�Ӹ� : %d�� %d��\n", snake.back().first, snake.back().second); // test
		printf("���� : %d�� %d��\n", snake.front().first, snake.front().second); // test
	}

}

bool isApple(pii* apple, int row, int col, int K) {
	for (int i = 0; i < K; i++) {
		if (row == apple[i].first)
			if (col == apple[i].second)
				return true;
	}
	return false;
}

void changeDirection(char& dir, char cmd) {
	if (cmd == 'L') {	// �������� 90�� ȸ��
		switch (dir) {
		case 'L':
			dir = 'D';
			break;
		case 'R':
			dir = 'U';
			break;
		case 'U':
			dir = 'L';
			break;
		case 'D':
			dir = 'R';
			break;
		}
	}
	else if (cmd == 'D') {	// ���������� 90�� ȸ��
		switch (dir) {
		case 'L':
			dir = 'U';
			break;
		case 'R':
			dir = 'D';
			break;
		case 'U':
			dir = 'R';
			break;
		case 'D':
			dir = 'L';
			break;
		}
	}
}

bool isHitWall(queue<pii> snake, int N) {
	if (snake.back().first > N || snake.back().second > N)
		return true;
	else if (snake.back().first == 0 || snake.back().second == 0)
		return true;
	else
		return false;
}

bool isHitBody() {

}