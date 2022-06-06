#include <iostream>
using namespace std;

typedef long long ll;

#define MAX_N 100000

int length[MAX_N];	// length[i]: i에서 i+1주유소 까지의 거리
int price[MAX_N];	// prices[i]: i번째 주유소의 리터당 가격


int main() {
	int N;
	cin >> N;

	for (unsigned i = 0; i < N-1; i++)
		cin >> length[i];

	for (unsigned i = 0; i < N; i++)
		cin >> price[i];

	int curr = 0;
	ll cost = 0;
	int min_price = price[curr];
	while (curr != N-1) {
		min_price = min(min_price, price[curr]);
		ll curr_cost = (ll)min_price * (ll)length[curr];
		cost += curr_cost;
		curr++;
	}

	cout << cost;


	return 0;
}