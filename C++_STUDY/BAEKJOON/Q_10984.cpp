#include <iostream>
using namespace std;

int main() {
	int totalSeme, subjNum, credit, totalCred;
	double grade, gpa, totalgrade;

	cin >> totalSeme;

	for (int i = 0; i < totalSeme; i++) {
		totalgrade = 0.0;
		totalCred = 0;
		subjNum = 0;
		gpa = 0.0;

		cin >> subjNum;

		for (int j = 0; j < subjNum; j++) {
			cin >> credit >> grade;
			totalCred += credit;
			totalgrade += grade * credit;
		}

		gpa = totalgrade / totalCred;

		cout << fixed; // precision�� �Ҽ��� �Ʒ��� ��¹����� �����ϵ��� �Ѵ�.
		cout.precision(1); // �Ҽ��� �Ʒ� �� ��° �ڸ����� �ݿø�
		cout << totalCred << " " << gpa << endl;		
	}

	return 0;
}