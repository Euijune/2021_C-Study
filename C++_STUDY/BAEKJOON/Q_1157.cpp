#include <iostream>
#include <stack>
using namespace std;

void checkAlphabet(char a, int lst[26]);

int main() {
	char input[1000001];
	cin >> input;

	int apb[26], max = -1, indx = 0;
	for (int& elem : apb) {
		elem = 0;
	}
	
	// test cin
	/*for (char elem : input) {
		if (elem == '\0')	break;
		cout << elem << " ";
	}
	cout << endl;*/

	for (char& alphabet : input) {
		if (alphabet == '\0')	break;
		checkAlphabet(alphabet, apb);
	}

	// test checkAlphabet function
	/*for (int elem : apb) {
		cout << elem << " ";
	}
	cout << endl;*/


	for (int& elem : apb)	max = elem > max ? elem : max;
	// test max int
	//cout << max << endl;

	stack<int> Ans;
	
	for (int i = 0; i < 26; i++) {
		if (apb[i] == max) {
			Ans.push(i);
		}
	}

	int SIZE = Ans.size();
	if (SIZE == 1) {
		cout << (char)(Ans.top() + 'A');
	}
	else {
		cout << "?";
	}

	return 0;
}

void checkAlphabet(char a, int lst[26]) {
	if (a >= 'a') { // Capital -> small 
		a = (char)(a - 32);
	}
	lst[a - 'A']++;
}