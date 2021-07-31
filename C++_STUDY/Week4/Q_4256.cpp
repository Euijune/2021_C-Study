#include <iostream>
#include <vector>
using namespace std;
vector<int> preorder;
vector<int> inorder;



void f(int start, int end, int pos);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n, temp;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		preorder.clear();
		inorder.clear();

		for (int j = 0; j < n; j++) {	// 전위순회
			cin >> temp;
			preorder.push_back(temp);
		}
		for (int k = 0; k < n; k++) {	// 중위순회
			cin >> temp;
			inorder.push_back(temp);
		}

		f(0, n, 0);
		cout << "\n";
	}

	return 0;
}


void f(int start, int end, int pos) {
	for (int i = start; i < end; i++) {
		if (preorder[pos] == inorder[i]) {
			f(start, i, pos + 1);	// left subtree searching
			f(i + 1, end, pos + i - start + 1);	// right subtree searching
			cout << inorder[i] << " ";
		}
	}
}
