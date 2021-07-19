#include <iostream>
#include <set>
using namespace std;

int main() {
	int n, remain;
	set<int> s;
	for (int i = 0; i < 10; i++) {
		remain = 0;
		cin >> n;
		remain = n % 42;
		s.insert(remain);
	}
	cout << s.size() << endl;

	return 0;
}