#include <iostream>
#include <list>
using namespace std;

#define endl '\n'
#define MAX 9

int sudocu[MAX][MAX];
void DFS(int, int);
void check_horizontal(list<int>&, int);
void check_vertical(list<int>&, int);
void check_square(list<int>&, int, int);
void printAll();

int main() {
	// For Fast I/O
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for (int row = 0; row < MAX; row++)
		for (int col = 0; col < MAX; col++)
			cin >> sudocu[row][col];

	DFS(0, 0);

	return 0;
}

void check_horizontal(list<int>& n, int x) {
	for (int col = 0; col < MAX; col++)
		if (sudocu[x][col] != 0)
			n.remove(sudocu[x][col]);
}
void check_vertical(list<int>& n, int y) {
	for (int row = 0; row < MAX; row++)
		if (sudocu[row][y] != 0)
			n.remove(sudocu[row][y]);
}
void check_square(list<int>& n, int x, int y) {
	for (int row = 0 + 3 * (x / 3); row < 3 * (x / 3 + 1); row++)
		for (int col = 0 + 3 * (y / 3); col < 3 * (y / 3 + 1); col++)
			if (sudocu[row][col] != 0)
				n.remove(sudocu[row][col]);
}

void DFS(int x, int y) {
	if (x == MAX) {
		printAll();
		cout << endl;
		exit(0);
	}

	if (sudocu[x][y] == 0) {
		list<int> numbers = { 1,2,3,4,5,6,7,8,9 };
		check_horizontal(numbers, x);
		check_vertical(numbers, y);
		check_square(numbers, x, y);

		for (int num : numbers) {
			sudocu[x][y] = num;
			if (y + 1 == MAX)
				DFS(x + 1, 0);
			else
				DFS(x, y + 1);
		}
		sudocu[x][y] = 0;
	}
	else {
		if (y + 1 == MAX)
			DFS(x + 1, 0);
		else
			DFS(x, y + 1);
	}
}

void printAll() {
	for (int row = 0; row < MAX; row++) {
		for (int col = 0; col < MAX; col++)
			if (col == MAX - 1)
				cout << sudocu[row][col];
			else
				cout << sudocu[row][col] << " ";
		cout << endl;
	}
}