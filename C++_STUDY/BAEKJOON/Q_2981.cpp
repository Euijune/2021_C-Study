// https://pangsblog.tistory.com/62 참고하여 풀었습니다.

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define endl '\n'

priority_queue<int, vector<int>, greater<int>> q;

int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

void find_divisor(int n) {
	for (int i = 1; i * i <= n; i++)
		if (i * i == n)
			q.push(i);
		else if (n % i == 0) {
			q.push(i);
			q.push(n / i);
		}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> numbers;
	int N, factor;
	cin >> N;
	numbers.resize(N);

	for (int i = 0; i < N; i++)
		cin >> numbers[i];
	sort(numbers.begin(), numbers.end());

	factor = numbers[1] - numbers[0];
	for (int i = 2; i < N; i++)
		factor = gcd(factor, numbers[i] - numbers[i - 1]);

	find_divisor(factor);

	q.pop();	// 1 제거
	while (!q.empty()) {
		cout << q.top() << endl;
		q.pop();
	}

	return 0;
}