#include <iostream>
#include  <vector>
using namespace std;

#define endl '\n'

int N;
int elem[3] = { 1,2,3 };
vector<int> seq, MIN;

void DFS(vector<int>, int);
bool split(vector<int>, int, int);
bool check_goodSeq(vector<int>, int, int, int);

int main() {
	MIN.reserve(N+2);
	seq.reserve(N+2);
	MIN.push_back(-1);

	cin >> N;
	seq.push_back(1);
	DFS(seq, 0);

	for (int i = 0; i < MIN.size(); i++)
		cout << MIN[i];

	return 0;
}

bool check_goodSeq(vector<int> v, int start, int mid, int end) {
	int i = start;
	int j = mid + 1;
	int count = 0;

	while (i <= mid && j <= end) {
		if (v[i] == v[j])
			count++;
		i++;
		j++;
	}
	if (count == mid + 1 - start)	return false;
	else							return true;
}

bool split(vector<int> v, int start, int end) {
	bool state1, state2, state, temp;
	if (start < end) {
		int mid = (start + end) / 2;
		state1 = split(v, start, mid);
		state2 = split(v, mid + 1, end);
		temp = check_goodSeq(v, start, mid, end);
		state = state1 && state2 && temp;
		return state;
	}
	return true;
}


void DFS(vector<int> v, int sp) {
	if (v.size() == N) {
		if (split(v, 0, v.size() - 1)) { // 좋은 수열인지 체크.
			if (MIN[0] == -1)
				MIN.assign(v.begin(), v.end());
			else if (v < MIN)
				MIN.assign(v.begin(), v.end());
		}
		return;
	}

	for (int i = 0; i < 3; i++) {
		if (v[sp] != elem[i]) {
			v.push_back(elem[i]);
			DFS(v, sp + 1);
			v.pop_back();
		}
	}
}