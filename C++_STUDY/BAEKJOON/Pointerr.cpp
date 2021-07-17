#include <iostream>
using namespace std;

int main() {
	int v1 = 1, v2 = 2, v3 = 3, v4 = 4, v5 = 5;
	int* num[5] = { &v1, &v2, &v3, &v4, &v5 };
	/*num[0] = &v1;
	num[1] = &v2;
	num[2] = &v3;
	num[3] = &v4;
	num[4] = &v5;*/

	cout << num << " " << num[1] << " " << *num[4];


	return 0;
}
