#include <iostream>
#include <memory.h>
using namespace std;

#define HOLE 0
#define CHEESE 1
#define AIR 2
#define endl '\n'

int M, N;
int grid[100][100];
int temp[100][100];
int drs[4] = { 1,-1, 0, 0 };
int dcs[4] = { 0, 0, 1, -1 };

bool inRange(int r, int c) {
	return 0 <= r && r < M && 0 <= c && c < N;
}

bool canGo(int r, int c) {
	return inRange(r, c) && grid[r][c] == 0;
}

void DFS(int r, int c) {
	grid[r][c] = AIR;

	for (int i = 0; i < 4; i++) {
		int nr = r + drs[i];
		int nc = c + dcs[i];

		if (canGo(nr, nc)) {
			grid[nr][nc] = AIR;
			DFS(nr, nc);
		}
	}
}

void setAir(int r, int c) {	// 지정한 위치와 연결된 모든 공기의 위치 설정
	DFS(r, c);
}

void saveTemp(int temp[][100]) {
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			grid[i][j] = temp[i][j];
}

bool findAdjustAir(int r, int c) {
	for (int i = 0; i < 4; i++) {
		int nr = r + drs[i];
		int nc = c + dcs[i];

		if (inRange(nr, nc) && grid[nr][nc] == AIR)
			return true;
	}

	return false;
}

void hole2Air() {	// 시간 경과 이후에, 치즈의 구멍에 공기가 들어가는 경우
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			if (grid[i][j] == HOLE && findAdjustAir(i, j))
				setAir(i, j);
}

void timeLapse(int& cheeseNum) {
	memset(temp, 0, sizeof(temp));

	for (int r = 0; r < M; r++)
		for (int c = 0; c < N; c++)
			if (grid[r][c] == CHEESE && findAdjustAir(r, c)) {
				temp[r][c] = AIR;
				cheeseNum--;
			}
			else
				temp[r][c] = grid[r][c];

	saveTemp(temp);
}

//void printArr(int arr[][100]) {
//	for (int i = 0; i < M; i++) {
//		for (int j = 0; j < N; j++)
//			cout << arr[i][j] << " ";
//		cout << endl;
//	}
//}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int number_of_cheese = 0;
	int save_cheese_num;
	cin >> M >> N;

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
			number_of_cheese = grid[i][j] == CHEESE ? number_of_cheese+1 : number_of_cheese;
		}

	setAir(0, 0);
	//printArr(grid);

	int time = 0;
	while (true) {
		save_cheese_num = number_of_cheese;
		timeLapse(number_of_cheese);
		hole2Air();
		time++;
		//cout << time << "시간 후, 치즈의 수 : "<<number_of_cheese << endl;
		//printArr(grid);

		if (number_of_cheese == 0)
			break;
	}

	cout << time << endl;
	cout << save_cheese_num;

	return 0;
}