#include <iostream>
using namespace std;

int main() {
	int schoolNum, studNum, aplNum, remainApl, share;
	cin >> schoolNum;

	remainApl = 0;
	for (int i = 0; i < schoolNum; i++) {
		cin >> studNum >> aplNum;
		
		share = aplNum / studNum;
		aplNum -= studNum * share;
		remainApl += aplNum;
	}

	cout << remainApl << endl;

	return 0;
}