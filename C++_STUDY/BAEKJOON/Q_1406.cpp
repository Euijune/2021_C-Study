#include <iostream>
#include <list>
using namespace std;

list<char> Editor;
int M;

void Print(list<char> lst);

int main() {
	// For fast I/O
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);

	string s;
	auto Cursor = Editor.end();

	cin >> s;
	for (int i = 0; i < s.size(); i++)
		Editor.push_back(s[i]);

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
			if (Cursor != Editor.begin())
				Cursor = Editor.erase(--Cursor);
			break;
		case 'P':
			cin >> chr;
			Cursor = Editor.insert(Cursor, chr);
			Cursor++;
		}
		//Debug
		/*Print(Editor);
		if (Cursor == Editor.end())			
			cout << "\t||\tCursor : END" << '\n';
		else
			cout << "\t||\tCursor : " << *Cursor << '\n';*/
		
	}

	Print(Editor);

	return 0;
}

void Print(list<char> lst) {
	for (auto it = lst.begin(); it != lst.end(); it++)
		cout << *it;
}