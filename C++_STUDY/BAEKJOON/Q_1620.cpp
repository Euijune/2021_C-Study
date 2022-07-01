#include <iostream>
#include <string>
#include <map>
using namespace std;

#define endl '\n'
#define MAXN 100001

map<string, int> i_book;
string arr[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		string p_name;
		cin >> p_name;
		i_book.insert({ p_name, i});
		arr[i] = p_name;
	}

	for (int i = 0; i < M; i++) {
		string temp;
		cin >> temp;

		if (i_book.find(temp) != i_book.end())
			cout << i_book.find(temp)->second << endl;
		else {
			int num = stoi(temp);
			cout << arr[num] << endl;
		}
	}

	return 0;
}