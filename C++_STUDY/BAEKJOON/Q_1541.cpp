#include <iostream>
#include <string>
using namespace std;

int main() {
	string equation;
	char mode = '+';
	int ans = 0;

	cin >> equation;

	for (int i = 0; i < equation.length(); i++) {
		if ('0' <= equation[i] && equation[i] <= '9') {
			string str = "";
			
			// 부호가 나오기 바로 전까지를 합쳐서 숫자를 만듦
			while (i < equation.length() && equation[i] != '+' && equation[i] != '-')
				str += equation[i++];
			
			if (mode == '+')
				ans += stoi(str);
			else
				ans -= stoi(str);

			// 여기서 i는 부호가 위치한 index
			if (mode == '+' && equation[i] == '-')
				mode = '-';
		}
	}

	cout << ans;

	return 0;
}