#include <stdio.h>
#include <queue>

using namespace std;
using pii = pair<int, int>;

void move(pii* apple, queue<pii>& snake, int& row, int& col, char dir, int N, int K, bool& gameover); // 뱀의 이동 구현
bool isApple(pii* apple, int row, int col, int K); // 사과를 만났는가?
void changeDirection(char& dir, char cmd);
void isHitWall(queue<pii> snake, int N, bool& gameover);
void isHitBody(queue<pii> snake, bool& gameover);
void showSnakeAll(queue<pii> snake);


int main() {
	bool gameover = false;
	int N, K, L, row, col, t, time = 0;
	char cmd, direction = 'R'; // Left, Right, Up, Down. 초기 방향은 오른쪽임

	queue<pii> snake({ {1,1} });	// 뱀의 몸에 대한 정보. front가 꼬리, back이 머리.
	printf("머리 : %d행 %d열\n", snake.back().first, snake.back().second); // test
	printf("꼬리 : %d행 %d열\n", snake.front().first, snake.front().second); // test
	queue<pii> dire;	//방향 전환에 대한 정보

	scanf_s("%d", &N);

	// 사과 위치 저장
	scanf_s("%d", &K);
	pii* apple = new pii[K];	// 사과 위치 정보

	for (int i = 0; i < K; i++) {
		scanf_s("%d %d", &row, &col);
		apple[i] = { row, col };
	}


	// 방향 전환정보 저장
	scanf_s("%d", &L);
	for (int i = 0; i < L; i++) {
		scanf_s("%d %c", &t, &cmd, 1);
		dire.push({ t, cmd });
	}

	while (true) {
		if (gameover)
			break;
		time++;	//매 초마다
		printf("====== time = %d ======\n\n", time); // test
		move(apple, snake, snake.back().first, snake.back().second, direction, N, K, gameover);
		// 주어진 조건에 따라 이동한다. move(queue, row, col, dir)

		if (!dire.empty()) {
			if (time == dire.front().first) { // 방향전환
				printf("방향전환 : %c\n", dire.front().second);	// test
				changeDirection(direction, dire.front().second);
				dire.pop();
			}
		}
		printf("snake size = %d\n\n", snake.size()); //test
	}
	printf("\nAnswer : %d", time);

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
	printf("현재 방향 : %c\n", dir);	// test
	if (isApple(apple, new_r, new_c, K)) {	//이동한 칸에 사과가 있을 경우
		snake.push({ new_r, new_c });
		printf("머리 : %d행 %d열\n", snake.back().first, snake.back().second); // test
		printf("꼬리 : %d행 %d열\n", snake.front().first, snake.front().second); // test
	}
	else {				// 이동한 칸에 사과가 없을 경우
		snake.push({ new_r, new_c });
		isHitBody(snake, gameover);
		isHitWall(snake, N, gameover);
		snake.pop();
		printf("머리 : %d행 %d열\n", snake.back().first, snake.back().second); // test
		printf("꼬리 : %d행 %d열\n", snake.front().first, snake.front().second); // test
	}
	showSnakeAll(snake);
}

bool isApple(pii* apple, int row, int col, int K) {
	for (int i = 0; i < K; i++) {
		if (row == apple[i].first)
			if (col == apple[i].second) {
				apple[i] = { -1,-1 }; //한번 먹은 사과는 사라진다.
				return true;
			}
	}
	return false;
}

void changeDirection(char& dir, char cmd) {
	if (cmd == 'L') {	// 왼쪽으로 90도 회전
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
	else if (cmd == 'D') {	// 오른쪽으로 90도 회전
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
		printf("HitWall.\n"); // test
	}
	else if (snake.back().first == 0 || snake.back().second == 0) {
		gameover = true;
		printf("HitWall.\n"); // test
	}
}

void isHitBody(queue<pii> snake, bool& gameover) {
	while (snake.size() > 1) {
		if (snake.front().first == snake.back().first) {
			if (snake.front().second == snake.back().second) {
				gameover = true;
				printf("HitBody.\n"); // test
				break;
			}
		}
		snake.pop();
	}
}

void showSnakeAll(queue<pii> snake) {
	while (!snake.empty()) {
		printf("[%d , %d] ", snake.front().first, snake.front().second);
		snake.pop();
	}
	printf("\n");
}