#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, M, length = 0;
	cin >> N >> M;

	bool IsLengthOver = false;
	string N_str = to_string(N);
	int N_strLength = N_str.length();

	if (N_strLength * N <= M) {
		for (int i = 0; i < N; i++) {
			cout << N;
		}
	}
	else {
		while (!IsLengthOver) {
			for (char elem : N_str) {
				cout << elem;
				length++;

				if (length == M) {
					IsLengthOver = true;
					break;
				}
			}
		}
	}

	return 0;
}