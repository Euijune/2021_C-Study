#include <iostream>
#include <vector>
using namespace std;

int main() {
	int directedG[10][10] = { };	// 인접행렬
	int unDirectedG[10][10] = {};	// 인접행렬
	vector<int> dirtG[10];			// 인접리스트
	vector<int> unDirtG[10];		// 인접리스트

	int v, e;
	cin >> v >> e;

	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		directedG[a][b] = 1;
		unDirectedG[a][b] = 1;
		unDirectedG[b][a] = 1;

		dirtG[a].push_back(b);
		unDirtG[a].push_back(b);
		unDirtG[b].push_back(a);
	}

	for (int i = 0; i < e; i++) {
		for (int j = 0; j < e; j++) {
			cout << directedG[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < e; i++) {
		for (int j = 0; j < e; j++) {
			cout << unDirectedG[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < e; i++) {
		cout << i << " ";
		for (int j = 0; j < dirtG[i].size(); j++) {
			cout << dirtG[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < e; i++) {
		cout << i << " ";
		for (int j = 0; j < unDirtG[i].size(); j++) {
			cout << unDirtG[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}