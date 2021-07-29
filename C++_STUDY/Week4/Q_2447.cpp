#include <stdio.h>
#include <string>	//memset 함수 백준에서 동작

std::string* matrix(int n) {
	std::string* arr = new std::string [n+3];

	return arr;
}

void printMatrix(std::string* arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%s\n", arr[i].c_str());
	}
}

void star(std::string* arr, int N, int row, int col) {	// row, col은 별을 그리게되는 시작점을 말한다. (default = (0,0))
	if (N == 1) {
		arr[0]= "*";
	}
	else if (N == 3) {	// default
		for (int i = row; i < 3 + row; i++) {
			arr[i] += "***";
		}
		arr[row + 1][col + 1] = ' ';
	}
	else {
		for (int i = row; i < 3 + row; i++) {
			for (int j = col; j < 3 + col; j++) {
				int n_row = row + (i - row) * N / 3;
				int n_col = col + (j - col) * N / 3;
				//cout << '\t' <<"N : "<<N/3<< " row : " << n_row << " col : " << n_col << endl;	//test
				star(arr, N / 3, n_row, n_col);
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
	scanf_s("%d", &N);
	std::string* arr;
	
	arr = matrix(N);
	star(arr, N, 0, 0);
	printMatrix(arr, N);

	delete[] arr;

	return 0;
}