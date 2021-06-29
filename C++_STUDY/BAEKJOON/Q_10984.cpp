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

		cout << fixed; // precision이 소수점 아래의 출력범위만 설정하도록 한다.
		cout.precision(1); // 소수점 아래 두 번째 자리에서 반올림
		cout << totalCred << " " << gpa << endl;		
	}

	return 0;
}