#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
#define MAXN 500000

ll seq[MAXN];
int N;

bool is_square_num(ll x, ll y) {
	if (sqrt(x) - (ll)sqrt(x) == 0 && sqrt(y) - (ll)sqrt(y) == 0)	// x, y가 너무 큰 숫자(10^16 등)일 경우
		return true;

	double z = sqrt(x * y);
	return z - (ll) z == 0;
}

bool swap(ll* data, int a, int b) {
	ll x = data[a], y = data[b];
	bool ret;	// x, y 가 square num이면 true, 아니면 x, y 사이의 수와 교환되었다는 것을 알리기 위해 false

	// 제곱수면 두 수의 위치를 바꿈
	if (is_square_num(x, y)) {
		ll temp = data[a];
		data[a] = data[b];
		data[b] = temp;
		ret = true;
	}
	else {
		bool check = false;	// x와 y를 바꾸지 못하여 그 사이의 수를 탐색해 제곱수이면 교환해봄
		ret = false;
		for (int i = min(a, b)+1; i < max(a, b); i++) {
			ll z = data[i];

			//if (i == a || i == b)	continue;	// 자기 자신과는 swap할 필요가 없다.
			
			if (x != z && is_square_num(x, z)) {
				swap(data, a, i);
				check = true;
				break;
			}
			else if (y != z && is_square_num(y, z)){
				swap(data, b, i);
				check = true;
				break;
			}
		}
		if (!check) {	// 만약 x나 y와 제곱수를 만들 수 있는 수가 존재하지 않으면 NO
			cout << "NO";
			exit(0);
		}
	}
	return ret;
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
		bool can_swap;	// swap으로 입력된 두 숫자가 서로 바뀌었는가? 
		while (i <= end && data[i] <= data[pivot])
			i++;
		while (start < j && data[pivot] <= data[j])
			j--;

		// 엇갈림
		if (i > j)
			can_swap = swap(data, j, pivot);
		else
			can_swap = swap(data, i, j);

		for (int i = 0; i < N; i++)
			cout << seq[i] << " ";
		cout << endl << endl;

		if (!can_swap) {	// swap의 두 수가 바뀌지 않고, 다른수와 바뀌었으므로 i와 j를 초기화하여 다시 탐색
			i = pivot + 1;
			j = end;
		}
	}

	quick_sort(data, start, j - 1);
	quick_sort(data, j + 1, end);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> seq[i];

	quick_sort(seq, 0, N - 1);
	cout << "YES";

	return 0;
}