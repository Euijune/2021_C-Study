# include <iostream>

using namespace std;

int main() {
	int N, count = 0;
	cin >> N;

	int* num = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}


	int v;
	cin >> v;
	for (int i = 0; i < N; i++) {
		cout << num[i] << endl;
		if (num[i] - v == 0) {
			count++;
		}
	}
	cout << count;

	return 0;
}