#include <stdio.h>
#include <queue>
using namespace std;

class answ {
public:
	bool operator() (pair<int, int>& lhs, pair<int, int>& rhs) const {
		return lhs.second > rhs.second; // 두 번째 원소 오름차순
	}
};

class comp2 {
public:
	bool operator() (pair<int, int>& lhs, pair<int, int>& rhs) const {
		if (lhs.first > rhs.first)
			return true; // 첫 번째 원소 오름차순
		else if (lhs.first == rhs.first)
			return lhs.second < rhs.second; // 두 번째 원소 내림차순
		else
			return false;
	}
};


int main() {

	priority_queue<pair<int, int>, vector<pair<int, int>>, answ> ans;
	priority_queue<pair<int, int>, vector<pair<int, int>>, comp2> hw2;
	int N, noodle, deadline, sum2 = 0, time2 = 0;
	scanf_s("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf_s("%d %d", &deadline, &noodle);
		hw2.push({ deadline, noodle });
	}

	while (!hw2.empty()){
		if (hw2.top().first > time2) {
			ans.push(hw2.top());
			sum2 += hw2.top().second;
			hw2.pop();
			time2++;
		}
		else if (hw2.top().first == time2) {
			if (hw2.top().second > ans.top().second) {
				ans.push(hw2.top());
				sum2 += hw2.top().second;
				sum2 -= ans.top().second;
				ans.pop();
				hw2.pop();
			}
			else {
				hw2.pop();
			}
		}
		else {
			hw2.pop();
		}
	}
	
	printf("%d", sum2);

	return 0;
}
