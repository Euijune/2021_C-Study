#include <iostream>
#include <vector>
using namespace std;

#define MAXN 50

typedef pair<int, int> pii;

vector<pii> user(MAXN);
vector<int> ranking(MAXN, 1);

void printAll(vector<int> v, int N) {
	for (int i = 0; i < N; i++)
		cout << v[i] << " ";
	cout << endl;
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int h, w;
		cin >> w >> h;

		user[i] = { w, h };
	}

	for (int i = 0; i < N; i++) {
		int h = user[i].second;
		int w = user[i].first;

		for (int j = 0; j < N; j++) {
			if (j == i)	continue;
			
			int hh = user[j].second;
			int ww = user[j].first;

			if (h < hh && w < ww)
				ranking[i]++;
		}
	}

	printAll(ranking, N);


	return 0;
}