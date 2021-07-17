#include <stdio.h>
#include <queue>

using namespace std;
using pii = pair<int, int>;

void move(pii* apple, queue<pii>& snake, int& row, int& col, char dir, int N, int K, bool& gameover); // ���� �̵� ����
bool isApple(pii* apple, int row, int col, int K); // ����� �����°�?
void changeDirection(char& dir, char cmd);
void isHitWall(queue<pii> snake, int N, bool& gameover);
void isHitBody(queue<pii> snake, bool& gameover);


int main() {
	bool gameover = false;
	int N, K, L, row, col, t, time = 0;
	char cmd, direction = 'R'; // Left, Right, Up, Down. �ʱ� ������ ��������

	queue<pii> snake({ {1,1} });	// ���� ���� ���� ����. front�� ����, back�� �Ӹ�.
	queue<pii> dire;	//���� ��ȯ�� ���� ����

	scanf("%d", &N);

	// ��� ��ġ ����
	scanf("%d", &K);
	pii* apple = new pii[K];	// ��� ��ġ ����

	for (int i = 0; i < K; i++) {
		scanf("%d %d", &row, &col);
		apple[i] = { row, col };
	}


	// ���� ��ȯ���� ����
	scanf("%d", &L);
	for (int i = 0; i < L; i++) {
		scanf("%d %c", &t, &cmd, 1);
		dire.push({ t, cmd });
	}

	while (true) {
		if (gameover)
			break;
		time++;	//�� �ʸ���
		move(apple, snake, snake.back().first, snake.back().second, direction, N, K, gameover);
		// �־��� ���ǿ� ���� �̵��Ѵ�. move(queue, row, col, dir)

		if (!dire.empty()) {
			if (time == dire.front().first) { // ������ȯ
				changeDirection(direction, dire.front().second);
				dire.pop();
			}
		}
	}
	printf("%d", time);

	delete[] apple;
	return 0;
}

void move(pii* apple, queue<pii>& snake, int& row, int& col, char dir, int N, int K, bool& gameover) {
	int new_r = 0, new_c = 0;

	switch (dir) {
	case 'U':
		new_r = row - 1;
		new_c = col;
		break;
	case 'D':
		new_r = row + 1;
		new_c = col;
		break;
	case 'R':
		new_r = row;
		new_c = col + 1;
		break;
	case 'L':
		new_r = row;
		new_c = col - 1;
		break;
	}
	if (isApple(apple, new_r, new_c, K)) {	//�̵��� ĭ�� ����� ���� ���
		snake.push({ new_r, new_c });
	}
	else {				// �̵��� ĭ�� ����� ���� ���
		snake.push({ new_r, new_c });
		isHitBody(snake, gameover);
		isHitWall(snake, N, gameover);
		snake.pop();
	}

}

bool isApple(pii* apple, int row, int col, int K) {
	for (int i = 0; i < K; i++) {
		if (row == apple[i].first)
			if (col == apple[i].second) {
				apple[i] = { -1, -1 }; // �ѹ� ���� ����� �������.
				return true;
			}
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

void isHitWall(queue<pii> snake, int N, bool& gameover) {
	if (snake.back().first > N || snake.back().second > N) {
		gameover = true;
	}
	else if (snake.back().first == 0 || snake.back().second == 0) {
		gameover = true;
	}
}

void isHitBody(queue<pii> snake, bool& gameover) {
	while (snake.size() != 1) {
		if (snake.front().first == snake.back().first) {
			if (snake.front().second == snake.back().second) {
				gameover = true;
			}
		}
		snake.pop();
	}
}