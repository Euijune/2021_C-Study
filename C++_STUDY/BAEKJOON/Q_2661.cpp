#include <iostream>
#include  <vector>
using namespace std;

#define endl '\n'

int N;
int elem[3] = { 1,2,3 };
vector<int> seq;

void DFS(vector<int>, int);
bool check(vector<int> v, int start, int mid, int end);
bool check_goodSeq(vector<int>, int, int, int);

int main() {
	seq.reserve(N + 2);

	cin >> N;
	seq.push_back(1);
	DFS(seq, 0);

	return 0;
}

bool check(vector<int> v, int start, int mid, int end) {

	int i = mid;
	int j = end;
	int count = 0;
	while (start <= i && mid + 1 <= j) {
		if (v[i] == v[j])
			count++;
		i--;
		j--;
	}
	if (count == mid + 1 - start)	return false;
	else							return true;
}

bool check_goodSeq(vector<int> v) {
	int size = v.size();
	bool goodSeq = true;

	for (int i = 1; i <= size / 2; i++) {
		int start = size - i*2;
		int end = size - 1;
		int mid = (start + end) / 2;
		goodSeq = check(v, start, mid, end);

		if (!goodSeq)	break;
	}
	return goodSeq;
}


void DFS(vector<int> v, int sp) {
	if (v.size() == N) {
		for (int i = 0; i < N; i++)
			cout << v[i];
		exit(0);
	}

	for (int i = 0; i < 3; i++)
		if (v[sp] != elem[i]) {
			v.push_back(elem[i]);
			if (check_goodSeq(v)) // 좋은 수열인지 체크.
				DFS(v, sp + 1);
			v.pop_back();
		}
}