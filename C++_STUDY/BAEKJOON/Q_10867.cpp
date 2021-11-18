#include <iostream>
#include <memory.h>

# define MAX 2001
int num_arr[MAX];
int N;

int main() {
	// For fast I/O
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

	memset(num_arr, 0, sizeof(int) * MAX);
	
	int temp;
	std::cin >> N;
	while (N--) {
		std::cin >> temp;
		num_arr[temp + 1000]++;
	}

	for (int i = 0; i < MAX; i++)
		if (num_arr[i])
			std::cout << i - 1000 << '\n';

	return 0;
}