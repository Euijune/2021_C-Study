#include <iostream>
#include <string>
using namespace std;

int main() {
	int studentNum;
	cin >> studentNum;

	string name;
	int mm, dd, yyyy;
	int mm_max, dd_max, yyyy_max;
	int mm_min, dd_min, yyyy_min;
	string ans_older, ans_younger;
	
	cin >> name >> dd >> mm >> yyyy;
	ans_older = name;
	ans_younger = name;
	mm_max = mm;
	mm_min = mm;
	dd_max = dd;
	dd_min = dd;
	yyyy_max = yyyy;
	yyyy_min = yyyy;

	while (studentNum-1) {
		cin >> name >> dd >> mm >> yyyy;

		if (yyyy > yyyy_max) {
			yyyy_max = yyyy;
			mm_max = mm;
			dd_max = dd;
			ans_younger = name;
		}
		else if ((yyyy == yyyy_max) && (mm > mm_max)) {
			mm_max = mm;
			dd_max = dd;
			ans_younger = name;
		}
		else if ((yyyy == yyyy_max) && (mm == mm_max) && (dd > dd_max)) {
			dd_max = dd;
			ans_younger = name;
		}
		else if (yyyy < yyyy_min) {
			yyyy_min = yyyy;
			mm_min = mm;
			dd_min = dd;
			ans_older = name;
		}
		else if ((yyyy == yyyy_min) && (mm < mm_min)) {
			mm_min = mm;
			dd_min = dd;
			ans_older = name;
		}
		else if ((yyyy == yyyy_min) && (mm == mm_min) && (dd < dd_min)) {
			dd_min = dd;
			ans_older = name;
		}

		studentNum--;
	}

	cout << ans_younger << "\n" << ans_older;
	return 0;
}