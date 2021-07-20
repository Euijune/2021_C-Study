#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;
using pii = pair<int, int>;

pii** dmatrix2D() {
	pii** Temp;
	
	Temp = new pii*[20];
	for (int i = 0; i < 20; i++) {
		int t = pow(2, i + 1) - 1;
		Temp[i] = new pii[t]; // Temp[0][0], Temp[1][0~3], Temp[2][0~7], ... , Temp[n][0~2^(n+1)-1];
	}

	for (int i = 0; i < 20; i++) {
		int t = pow(2, i + 1) - 1;
		for (int j = 0; j < t; j++) {
			Temp[i][j] = { 0,0 };
		}
	}

	return Temp;
}

void free_dmatrix2D(pii** Image){
	for (int y = 0; y < 20; y++)
		delete[] Image[y];

	delete[] Image;
}

int Zmod3PlusOne(int n) {
	if (n == 3)	return 1;
	else		return n + 1;
}

int change2to3(int n) {
	if (n == 1)	return 1;
	else		return abs(n - 5);
}

void move(int n, pii**& moveOrder) {
	int k = pow(2, n) - 1;
	int lastto3 = pow(2, n - 1)-1; // 2^(n-1)-1 index
	//printf("test:: lasto3, k :: %d, %d, %d\n", lastto3,k);
	if (n == 1) {
		moveOrder[0][0] = { 1,3 };
	}
	else if (n == 2) {
		moveOrder[1][0] = { 1,2 };
		moveOrder[1][1] = { 1,3 };
		moveOrder[1][2] = { 2,3 };
	}
	else {
		if (moveOrder[n - 2][0].first != 0) { // move(n-1)을 호출한 적이 있다면
			for (int i = 0; i < lastto3; i++) {
				moveOrder[n - 1][i].first = change2to3(moveOrder[n - 2][i].first);
				moveOrder[n - 1][i].second = change2to3(moveOrder[n - 2][i].second);	// 2->3, 3->2
			}
			moveOrder[n - 1][lastto3].first = 1;
			moveOrder[n - 1][lastto3].second = 3;
			for (int i = lastto3 + 1; i < k; i++) {	// k = 2^n-1
				moveOrder[n - 1][i].first = Zmod3PlusOne(moveOrder[n - 1][i - (lastto3+1)].first);
				moveOrder[n - 1][i].second = Zmod3PlusOne(moveOrder[n - 1][i - (lastto3+1)].second);
			}
		}
		else {	// move(n-1)을 호출한 적이 없다면
			move(n - 1, moveOrder);
			move(n, moveOrder);
		}
	}
}

void print(int indx, pii** vec) {
	for (int i = 0; i < round(pow(2, indx+1) - 1); i++) {
		printf("%d %d\n", vec[indx][i].first, vec[indx][i].second);
	}
}

int main() {
	int N, K;
	scanf_s("%d", &N);
	K = pow(2, N) - 1;
	printf("%d\n", K);

	pii** moveOrder = dmatrix2D();
	move(N, moveOrder);
	print(N-1, moveOrder);

	free_dmatrix2D(moveOrder);
	return 0;
}