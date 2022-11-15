#include <iostream>
using namespace std;

#define MAXN 50
#define MAXM 50

int N, M;
string A[MAXN];
string B[MAXN];
string C[MAXN];
bool visited[MAXN][MAXM];

void flip(int y, int x) {	// (0, 0) ------> x 
	visited[y][x] = true;
	int dx[9] = { 0, 1, 2, 0, 1, 2, 0, 1, 2};	// ї­
	int dy[9] = { 0, 0, 0, 1, 1, 1, 2, 2, 2 };	// За
	for (int dir = 0; dir < 9; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		C[ny][nx] = (C[ny][nx] == '1') ? '0' : '1';
	}
}

bool isAnswer() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++){
			if (C[i][j] == '0')
				return false;
		}
	}
	return true;
}

int main() {
	int cnt_of_calc = 0;
	cin >> N >> M;	

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}

	for (int i = 0; i < N; i++) {
		string lines;
		for (int j = 0; j < M; j++)
			if (A[i][j] == B[i][j])
				lines += '1';
			else
				lines += '0';
		C[i] = lines;
	}

	cout << endl;
	for (int i = 0; i < N; i++) {
		cout << C[i];
		cout << endl;
	}

	for (int y = 0; y < N - 2; y++) {
		for (int x = 0; x < M - 2; x++) {
			if (C[y][x] == '0') {
				flip(y, x);
				cnt_of_calc++;

				cout << endl;
				for (int i = 0; i < N; i++) {
					cout << C[i];
					cout << endl;
				}
			}
		}
	}

	if (isAnswer())
		cout << cnt_of_calc;
	else
		cout << -1;


	return 0;
}