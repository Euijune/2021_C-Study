#include <stdio.h>
#include <queue>

using namespace std;
using pii = pair<int, int>;

void move(pii* apple, queue<pii>& snake, int& row, int& col, char dir, int K); // 뱀의 이동 구현
bool isApple(pii* apple, int row, int col, int K); // 사과를 만났는가?
void changeDirection(char& dir, char cmd);
bool isHitWall(queue<pii> snake, int N);
bool isHitBody(); // 구현해야 함
//bool gameOver(isHitWall(), isHitBody()); // 구현


int main() {
	int N, K, L, row, col, t, time = 0;
	char cmd, direction = 'R'; // Left, Right, Up, Down. 초기 방향은 오른쪽임

	queue<pii> snake({ {1,1} });	// 뱀의 몸에 대한 정보. front가 꼬리, back이 머리.
	printf("초기위치 : %d행 %d열\n", snake.back().first, snake.back().second); // test
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
	
	while (!isHitWall(snake, N)) {
		time++;	//매 초마다
		printf("====== time = %d ======\n\n", time);
		move(apple, snake, snake.front().first, snake.front().second, direction, K);	// 주어진 조건에 따라 이동한다. move(queue, row, col, dir)
		
		if (time == dire.front().first) { // 방향전환
			printf("방향전환 : %c\n", dire.front().second);	//test
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

	if (isApple(apple, row, col, K)) {	//이동한 칸에 사과가 있을 경우
		snake.push({ new_r, new_c });
		printf("머리 : %d행 %d열\n", snake.back().first, snake.back().second); // test
		printf("꼬리 : %d행 %d열\n", snake.front().first, snake.front().second); // test
	}
	else {				// 이동한 칸에 사과가 없을 경우
		snake.push({ new_r, new_c });
		snake.pop();
		printf("머리 : %d행 %d열\n", snake.back().first, snake.back().second); // test
		printf("꼬리 : %d행 %d열\n", snake.front().first, snake.front().second); // test
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