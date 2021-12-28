#include <iostream>
#include <cmath>
#include <vector>

#define endl "\n"
using namespace std;

typedef pair<int, int> pii;

int N, M, chicken_num, house_num, v_num, ans = 9999999;
vector<pii> House, Chicken, V;
bool Select[13];

int min(int, int);
int calc_chicken_distance();	// 치킨집을 M개로 줄였을때 도시의 치킨거리를 구하는 함수
void select_chicken(int, int);	// M개의 치킨집을 고르는 함수

int main() {
	// For Fast I/O
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	int tmp;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			cin >> tmp;
			if (tmp == 1)
				House.push_back({ i,j });
			else if (tmp == 2)
				Chicken.push_back({ i, j });
		}
	chicken_num = Chicken.size();
	house_num = House.size();
	v_num = M;

	select_chicken(0, 0);
	cout << ans << endl;

	return 0;
}

int min(int A, int B) {
	if (A > B)	return B;
	return A;
}

int calc_chicken_distance() {
	int sum = 0;
	for (int i = 0; i < house_num; i++) {
		int x = House[i].first;
		int y = House[i].second;
		int d = 9999999;

		for (int j = 0; j < v_num; j++) {
			int xx = V[j].first;
			int yy = V[j].second;
			int Dist = abs(xx - x) + abs(yy - y);

			d = min(d, Dist);
		}
		sum += d;
	}
	return sum;
}
void select_chicken(int Idx, int Cnt) {
	if (Cnt == M) {
		ans = min(ans, calc_chicken_distance());
		return;
	}

	for (int i = Idx; i < chicken_num; i++) {
		Select[i] = true;
		V.push_back(Chicken[i]);
		select_chicken(i + 1, Cnt + 1);
		Select[i] = false;
		V.pop_back();
	}
}

