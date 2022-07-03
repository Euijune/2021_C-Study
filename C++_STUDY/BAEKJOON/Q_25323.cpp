#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
#define MAXN 500000

ll seq[MAXN];

bool is_square_num(ll x, ll y) {
	auto z = sqrt(x * y);
	return z == (ll)z;
}

void swap(ll* data, int a, int b) {
	ll x = data[a], y = data[b];

	// 제곱수면 두 수의 위치를 바꿈
	if (is_square_num(x, y)) {
		ll temp = data[a];
		data[a] = data[b];
		data[b] = temp;
	}
	else {
		cout << "NO";
		exit(0);
	}
}

void quick_sort(ll* data, int start, int end) {
	// 원소가 1개인 경우
	if (start >= end)
		return;

	int pivot = start;
	int i = pivot + 1;
	int j = end;

	// i와 j가 엇갈릴 때까지 반복
	while (i <= j) {
		
		while (i <= end && data[i] <= data[pivot])
			i++;
		while (start < j && data[pivot] <= data[j])
			j--;

		// 엇갈림
		if (i > j)
			swap(data, j, pivot);
		else
			swap(data, i, j);
	}

	quick_sort(data, start, j - 1);
	quick_sort(data, j + 1, end);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> seq[i];

	quick_sort(seq, 0, N-1);
	cout << "YES";

	return 0;
}