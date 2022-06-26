#include <iostream>
#include <algorithm>
#include <cmath>
#include <memory.h>
using namespace std;

#define MAXN 500000
#define MAXSIZE 8001
#define endl '\n'

int coordinate[MAXN];
int nums[MAXSIZE];

// 최빈값
int find_mode() {
	int freq = 0, idx = 0;

	for (int i = 0; i < MAXSIZE; i++)
		if (freq < nums[i]) {
			freq = nums[i];
			idx = i;
		}

	// 두번째로 작은 최빈값
	for (int j = idx + 1; j < MAXSIZE; j++)
		if (freq == nums[j]) {
			idx = j;
			break;
		}

	return idx - 4000;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	double sum = 0.0;
	int N;
	cin >> N;

	memset(nums, 0, sizeof(int) * MAXSIZE);

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		sum += (double)temp;
		nums[temp + 4000]++;
		coordinate[i] = temp;
	}

	sort(coordinate, coordinate + N);

	int mean = round(sum / N);
	if (mean == -0) mean = 0;

	int median, mode, range;
	median = coordinate[N / 2];
	mode = find_mode();
	range = coordinate[N - 1] - coordinate[0];

	cout << mean << endl << median << endl << mode << endl << range;

	return 0;
}