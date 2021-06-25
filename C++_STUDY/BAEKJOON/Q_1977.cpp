// 나의 제출
/*
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int M, N, index = 0, sum = 0;
	cin >> M >> N;

	int sqr_num_max = sqrt(N), sqr_num_min = sqrt(M);
	int length = (sqr_num_max - sqr_num_min) + 1;

	int* arr = new int[length]();

	for (int i = M; i < N + 1; i++) {
		double d_s = sqrt(i);
		int i_s = d_s;

		if (d_s == i_s) {
			arr[index] = i;
			index++;
		}
	}

	for (int j = 0; j < length; j++) {
		sum += arr[j];
	}
	
	if (sum > 0)	cout << sum << '\n' << arr[0];
	else			cout << -1;

	delete[] arr;

	return 0;
}
*/

// 메모리 최소화
#include <iostream>
using namespace std;

int main() {
	int n, m, sum = 0, min = 10000;
	scanf_s("%d %d", &n, &m);

	for (int i = 1; i <= 100; i++) {
		if (i * i >= n && i * i <= m) {
			sum += (i * i);
			if (min > i * i) {
				min = i * i;
			}
		}
	}

	if (sum > 0)	cout << sum << '\n' << min;
	else			cout << -1;

	return 0;
}