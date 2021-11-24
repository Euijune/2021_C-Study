#include <iostream>
using namespace std;

#define MAX 20

int N, S, res = 0;
int numArr[MAX];

void find(int indx, int sum);

int main() {
	//For fast I/O
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> S;

	for (int i = 0; i < N; i++) 
		cin >> numArr[i];

	find(0, 0);
	cout << res;

	return 0;
}

void find(int indx, int sum) {
	if (indx == N)	
		return;
	sum += numArr[indx];
	if (sum == S)	
		res++;

	find(indx + 1, sum);	// 현 index를 포함하는 solution
	find(indx + 1, sum - numArr[indx]);	// 현 index를 포함하지 않는 solution
}