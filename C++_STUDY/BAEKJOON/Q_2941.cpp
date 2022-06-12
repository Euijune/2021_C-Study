#include <iostream>
#include <string>
using namespace std;

string cro_alphabets[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main() {
	int cnt = 0;
	string word;
	cin >> word;

	for (int i = 0; i < 8; i++) {
		int idx = word.find(cro_alphabets[i]);
		while (idx != string::npos) {
			word.replace(idx, cro_alphabets[i].length(), "a");
			idx = word.find(cro_alphabets[i]);				
		}
	}
	cout << word.length();


	return 0;
}