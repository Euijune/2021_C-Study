// 이전에 제출한 알고리즘을 개선하였습니다.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
	string name;
	int d, m, y;
};

int index(vector<Student> arr, int size, Student ins);

int main() {
	int n;
	cin >> n;

	vector<Student> s;

	for (int i = 0; i < n; i++) {
		Student temp;
		cin >> temp.name >> temp.d >> temp.m >> temp.y;
		s.insert(s.begin() + index(s, i, temp), temp);
	}

	cout << s[n - 1].name << '\n' << s[0].name;

	return 0;
}

int index(vector<Student> arr, int size, Student temp)
{
	for (int i = 0; i < size; i++) {
		if (arr[i].y > temp.y) {
			return i;
		}
		else if ((arr[i].y == temp.y) && (arr[i].m > temp.m)) {
			return i;
		}
		else if ((arr[i].y == temp.y) && (arr[i].m == temp.m) && (arr[i].d == temp.d)) {
			return i;
		}
	}

	return size;
}