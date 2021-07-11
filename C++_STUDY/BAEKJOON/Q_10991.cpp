#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		unsigned int cal = N + 2 - i;
		cout << setw(cal);
		for (int j = 0; j < i; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}

	return 0;
}