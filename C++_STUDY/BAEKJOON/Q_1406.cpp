#include <iostream>
#include <string>
using namespace std;

string Editor;
int M;

int main() {
	cin >> Editor;
	auto Cursor = Editor.end();

	char cmd;
	char chr;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> cmd;

		switch (cmd) {
		case 'L':
			Cursor = Cursor == Editor.begin() ? Cursor : --Cursor;
			break;
		case 'D':
			Cursor = Cursor == Editor.end() ? Cursor : ++Cursor;
			break;
		case 'B':
			if (Cursor != Editor.begin()) {
				Cursor = Editor.erase(--Cursor);
			}
			break;
		case 'P':
			cin >> chr;
			Editor.insert(Cursor, chr);
		}
		//Debug
		//cout << Editor << '\n';
	}

	for (auto it = Editor.begin(); it != Editor.end(); it++)
		cout << *it;

	return 0;
}