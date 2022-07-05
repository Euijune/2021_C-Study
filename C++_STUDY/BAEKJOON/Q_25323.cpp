#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
#define MAXN 500000

ll seq[MAXN];
int N;

bool is_square_num(ll x, ll y) {
	if (sqrt(x) - (ll)sqrt(x) == 0 && sqrt(y) - (ll)sqrt(y) == 0)	// x, y�� �ʹ� ū ����(10^16 ��)�� ���
		return true;

	double z = sqrt(x * y);
	return z - (ll) z == 0;
}

bool swap(ll* data, int a, int b) {
	ll x = data[a], y = data[b];
	bool ret;	// x, y �� square num�̸� true, �ƴϸ� x, y ������ ���� ��ȯ�Ǿ��ٴ� ���� �˸��� ���� false

	// �������� �� ���� ��ġ�� �ٲ�
	if (is_square_num(x, y)) {
		ll temp = data[a];
		data[a] = data[b];
		data[b] = temp;
		ret = true;
	}
	else {
		bool check = false;	// x�� y�� �ٲ��� ���Ͽ� �� ������ ���� Ž���� �������̸� ��ȯ�غ�
		ret = false;
		for (int i = min(a, b)+1; i < max(a, b); i++) {
			ll z = data[i];

			//if (i == a || i == b)	continue;	// �ڱ� �ڽŰ��� swap�� �ʿ䰡 ����.
			
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
		if (!check) {	// ���� x�� y�� �������� ���� �� �ִ� ���� �������� ������ NO
			cout << "NO";
			exit(0);
		}
	}
	return ret;
}

void quick_sort(ll* data, int start, int end) {
	// ���Ұ� 1���� ���
	if (start >= end)
		return;

	int pivot = start;
	int i = pivot + 1;
	int j = end;

	// i�� j�� ������ ������ �ݺ�
	while (i <= j) {
		bool can_swap;	// swap���� �Էµ� �� ���ڰ� ���� �ٲ���°�? 
		while (i <= end && data[i] <= data[pivot])
			i++;
		while (start < j && data[pivot] <= data[j])
			j--;

		// ������
		if (i > j)
			can_swap = swap(data, j, pivot);
		else
			can_swap = swap(data, i, j);

		for (int i = 0; i < N; i++)
			cout << seq[i] << " ";
		cout << endl << endl;

		if (!can_swap) {	// swap�� �� ���� �ٲ��� �ʰ�, �ٸ����� �ٲ�����Ƿ� i�� j�� �ʱ�ȭ�Ͽ� �ٽ� Ž��
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