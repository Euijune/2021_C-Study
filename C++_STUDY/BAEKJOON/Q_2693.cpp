#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		priority_queue <int, vector<int>, less<int>> Q;
		for (int i = 0; i < 10; i++) {
			int tmp;
			cin >> tmp;
			Q.push(tmp);
		}
		Q.pop();
		Q.pop();
		cout << Q.top() << endl;
	}

	return 0;
}

//void swap(int& x, int& y) {
//	int temp = x;
//	x = y;
//	y = temp;
//}
//
//int main() {
//	int T;
//	cin >> T;
//
//	while (T--) {
//		int arr[10];
//		for (int i = 0; i < 10; i++) {
//			cin >> arr[i];
//		}
//		for (int i = 0; i < 10; i++) {
//			for (int j = 0; j < 9; j++) {
//				if (arr[j] > arr[j + 1])	swap(arr[j], arr[j + 1]);
//			}
//		}
//		cout << arr[7] << endl;
//	}
//	return 0;
//}