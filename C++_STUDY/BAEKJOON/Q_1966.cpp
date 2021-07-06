#include <iostream>
#include <functional>
using namespace std;

int main() {

	int T, N, prior, findOrderIndx, endflag, indx, doc;
	pair<int, char> temp;
	cin >> T;

	for (int i = 0; i < T; i++) {
		doc = 0;
		indx = 0;
		cin >> N >> findOrderIndx;
		pair<int, char>* printer = new pair<int, char>[N];

		for (int j = 0; j < N; j++) { // 동적 배열에 값을 채워넣는 과정
			cin >> prior;
			printer[j] = { prior, doc };
			doc++;
		}

		while (indx != N) {
			endflag = 0;

			for (int i = indx+1; i < N; i++) { // 정렬 과정

				if (printer[indx].first < printer[i].first) {
					temp = printer[indx];

					for (int j = indx+1; j < N; j++) {
						printer[j - 1] = printer[j];
					}

					printer[N - 1] = temp;
					endflag = 1;
					break;
				}
			}
			if (endflag) continue;
			indx++;
		}
		for (int z = 0; z < N; z++) {

			if (printer[z].second == findOrderIndx) {
				cout << z + 1 << endl;
				break;
			}
		}
		delete[] printer;
	}
	return 0;
}