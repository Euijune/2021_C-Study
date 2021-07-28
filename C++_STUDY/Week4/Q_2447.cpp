#include <iostream>
#include <cstring>	//memset 함수 백준에서 동작
using namespace std;

char** matrix2D(int n) {
	char** arr = new char* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new char[n];
		memset(arr[i], '0', n * sizeof(char));
	}

	return arr;
}

void deleteMatrix2D(char** arr, int n) {
	for (int i = 0; i < n; i++) {
		delete[] arr[i]; 
	} 
	delete[] arr;

}

void printMatrix2D(char** arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
}

void star(char** arr, int N, int row, int col) {
	if (N == 1) {
		arr[0][0] = '*';
	}
	else if (N == 3) {	// default
		for (int i = row; i < N + row; i++) {
			for (int j = col; j < N + col; j++) {
				arr[i][j] = '*';
			}
		}
		arr[row+1][col+1] = ' ';
	}
	else {
		for (int i = row; i < 3 + row; i++) {
			for (int j = col; j < 3 + col; j++) {
				int n_row = (i-row) * N/3 + row;
				int n_col = (j-col) * N/3 + col;
				//cout << '\t' <<"N : "<<N/3<< " row : " << n_row << " col : " << n_col << endl;	//test
				star(arr, N / 3, n_row, n_col); // star(arr, N/3, row, col);

			}
		}
		for (int i = N / 3 + row; i < N * 2 / 3 + row; i++) {
			for (int j = N / 3 + col; j < N * 2 / 3 + col; j++) {
				arr[i][j] = ' ';
			}
		}
	}
}

int main() {
	int N;
	cin >> N;
	char** arr;
	
	arr = matrix2D(N);
	star(arr, N, 0, 0);
	printMatrix2D(arr, N);

	deleteMatrix2D(arr, N);

	return 0;
}