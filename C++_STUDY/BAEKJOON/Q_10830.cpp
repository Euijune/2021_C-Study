#include <iostream>
#include <vector>
using namespace std;

#define R 1000
#define endl '\n'
typedef vector<vector<int>> vii;

ostream& operator<<(ostream& os, const vii matrix) {	// print matrix
	int N = matrix.size();
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++)
			os << matrix[r][c] << " ";
		os << endl;
	}
	return os;
}

vii operator%(vii matrix, const int remain) {	// A % remain	(A is matrix, r is scalar)
	int N = matrix.size();
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			matrix[r][c] = matrix[r][c] % remain;
	return matrix;
}

vii operator*(vii mat1, vii mat2) {		// A dot B	(A, B is matrix)
	int N = mat1.size();
	vii matrix(N, vector<int>(N, 0));

	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			for (int i = 0; i < N; i++)
				matrix[r][c] += mat1[r][i] * mat2[i][c];
	return matrix;
}

vii powMatrix(vii matrix, long long B) {
	if (B == 1)
		return matrix % R;

	vii matrix_k = powMatrix(matrix, B / 2);

	if (B % 2 == 0)
		return (matrix_k * matrix_k) % R;
	else
		return ((matrix_k * matrix_k) % R * (matrix % R)) % R;
}

int main() {
	int N;
	long long B;
	cin >> N >> B;

	vii matrix(N, vector<int>(N, 0));

	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			cin >> matrix[r][c];

	cout << powMatrix(matrix, B);

	return 0;
}