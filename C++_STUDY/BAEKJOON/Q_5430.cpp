#include <iostream>
#include <memory.h>
#include <string>
using namespace std;

int numList[100000];
int n;
char startToken = '[';
char endToken = ']';
char rest = ',';

void Input(string& p);
void operation(string& p, int* numList);

int main() {
	//For fast I/O
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	

	int T;
	cin >> T;

	while (T--) {
		// 배열 초기화
		string p;
		memset(numList, 0, sizeof(int) * 100000);

		// 입력 및 동작
		Input(p);
		operation(p, numList);

		cout << "\n";
	}

	return 0;
}
void Input(string& p) {
	cin >> p;
	cin >> n;

	cin >> startToken;
	for (int j = 0; j < n; j++) {
		cin >> numList[j];
		if (j != n - 1)	cin >> rest;
	}
	cin >> endToken;
}

void operation(string& p, int* numList) {
	int start = 0;
	int end = n - 1;
	bool ascend = true;
	bool empty = end == -1 ? true : false;

	for (char cmd : p) {
		if (cmd == 'R')
			ascend = !ascend;
		else {
			if (empty) {
				cout << "error";
				return;
			}
			if (start == end)	
				empty = true;
				
			if (ascend)	start++;
			else		end--;
		}
	}

	cout << startToken;
	if (ascend)
		for (int i = start; i <= end; i++) {
			cout << numList[i];
			if (i != end)	cout << rest;
		}
	else
		for (int i = end; i >= start; i--) {
			cout << numList[i];
			if (i != start)	cout << rest;
		}
	cout << endToken;
}