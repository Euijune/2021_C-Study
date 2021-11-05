#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

class comp {
public:
	bool operator()(const pii& lhs, const pii& rhs) {
		if (lhs.second == rhs.second)
			return lhs.first > rhs.first;
		else
			return lhs.second > rhs.second;		
	}
};

int main() {
	// For fast I/O
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int N;
	priority_queue<pii, vector<pii>, comp> q;

	cin >> N;
	for (int i = 0; i < N; i++) {
		pii temp;
		cin >> temp.first >> temp.second;
		q.push(temp);
	}
	
	while (!q.empty()) {
		cout << q.top().first << " " << q.top().second << endl;
		q.pop();
	}
	
	return 0;
}