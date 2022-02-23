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
			
			// ��ȣ�� ������ �ٷ� �������� ���ļ� ���ڸ� ����
			while (i < equation.length() && equation[i] != '+' && equation[i] != '-')
				str += equation[i++];
			
			if (mode == '+')
				ans += stoi(str);
			else
				ans -= stoi(str);

			// ���⼭ i�� ��ȣ�� ��ġ�� index
			if (mode == '+' && equation[i] == '-')
				mode = '-';
		}
	}

	cout << ans;

	return 0;
}