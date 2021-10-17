#include <iostream>
#include <memory.h>
using namespace std;

int main() {

	// for fast IO
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int N, num_list[10000];
	cin >> N;

	memset(num_list, 0, sizeof(num_list));

	while (N--) {
		int temp;
		cin >> temp;
		num_list[temp - 1]++;
	}

	for (int i = 0; i < 10000; i++) {
		int count = num_list[i];
		while (count--)
			cout << i+1 << '\n';
	}
}