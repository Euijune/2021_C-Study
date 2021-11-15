#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<string>> word_matrix;
string word;
int N;

// ������������ vector ����
template <class ItemType>
bool comp(ItemType& lhs, ItemType& rhs) {
	return lhs < rhs;
}

int main() {
	// for fast IO
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// initialize matrix
	vector<string> elem;
	for (int i = 0; i < 50; i++)
		word_matrix.push_back(elem);

	// ���� ���� (���� �ȵ�)
	cin >> N;
	while (N--) {
		cin >> word;
		word_matrix[word.size()-1].push_back(word);
	}

	// ���� �� ���
	for (vector<string> vec : word_matrix)
		if (!vec.empty()) {
			sort(vec.begin(), vec.end(), comp<string>);

			string preWord = "";
			for (string word : vec)
				if (preWord != word) {
					cout << word << '\n';
					preWord = word;
				}
		}

	return 0;
}