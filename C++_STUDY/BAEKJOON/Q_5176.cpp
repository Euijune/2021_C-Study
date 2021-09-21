#include <iostream>
using namespace std;

int main() {
	int K;
	cin >> K;

	while (K--) {
		int P, M, occupied = 0;
		cin >> P >> M;

		int* list = new int[M];
		/*memset(list, 1, M * sizeof(int));

		for (int i = 0; i < M; i++) {
			cout << *(list+i*sizeof(int)) << " ";
		}
		cout << endl;*/

		for (int i = 0; i < P; i++) {
			int tmp;
			cin >> tmp;
			list[tmp - 1] = 0;
		}

		for (int i = 0; i < M; i++) {
			if (list[i] == 0)	occupied++;
		}

		int ans = P - occupied;
		cout << ans << endl;
		
		delete[] list;
	}

	return 0;
}