#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main() {

	int T, N, prior, findOrderIndx;
	char doc;
	cin >> T;

	for (int i = 0; i < T; i++) {
		doc = 'A';
		cin >> N >> findOrderIndx;
		pair<int, char>* printer = new pair<int, char>[N];

		for (int j = 0; j < N; j++) {
			cin >> prior;
			printer[j] = { prior, doc };
			doc++;
		}

		// 여기서 각 테스트케이스에 대해 출력
		for (int i = 0; i < N; i++) {
			for (int j = i; j < N - i; j++) {
				
			}
			cout << printer[i].first << " " << printer[i].second << endl;
		}

		delete[] printer;
	}

	

	return 0;
}