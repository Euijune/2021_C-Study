#include <stdio.h>
#include <vector>
using namespace std;

int main() {
	int n;
	scanf_s("%d", &n);
	vector<int> binary;
	

	while (n >= 2) {
		if (n != 2 * (n / 2)) {	// 만약 n이 홀수라면
			binary.push_back(1);
		}
		else {
			binary.push_back(0);
		}
		n = n / 2;
	}
	binary.push_back(1);

	const int size = binary.size();
	for (int i = 0; i < size; i++) {
		printf("%d", binary.back());
		binary.pop_back();
	}

	return 0;
}