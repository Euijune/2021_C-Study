#include <iostream>
using namespace std;

int main() {
	int N = 3, M = 2;
	int m_price_burger = 2000, m_price_beverage = 2000;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		if (m_price_burger > tmp) {
			m_price_burger = tmp;
		}
	}

	for (int i = 0; i < M; i++) {
		int tmp;
		cin >> tmp;
		if (m_price_beverage > tmp) {
			m_price_beverage = tmp;
		}
	}

	cout << m_price_beverage + m_price_burger - 50;

	return 0;
}