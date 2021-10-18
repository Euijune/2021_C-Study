#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

#define MAX_VAL 10'000'000

int main() {
	//for fast IO
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, cardPool = 20000001;
	cin >> N;

	bool* numCard = new bool[cardPool];
	memset(numCard, false, cardPool * sizeof(bool));

	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		numCard[temp + MAX_VAL] = true;
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> temp;

		if (numCard[temp + MAX_VAL])	cout << 1 << " ";
		else							cout << 0 << " ";
	}

	return 0;
}