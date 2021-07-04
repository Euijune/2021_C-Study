#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	//For fast IO
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x, m = 2, endflag = 0;
	string ans = "";
	stack<int> seq;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;

		if (i == 0) { // 맨 처음 stack 완전히 비어있는 상태일때
			seq.push(1);
			ans.append("+\n");
		}

		while (x != (seq.empty() ? -1 : seq.top())) { // 실행 중간에 stack이 완전히 비는 경우 포함
			if (x < (seq.empty() ? -1 : seq.top())) { // NO가 출력되는 조건
				ans = "NO";
				endflag = 1; // while 바깥 for문 break
				break;
			}

			seq.push(m);
			ans.append("+\n");
			m++;
		}

		if (endflag) break;

		seq.pop();
		ans.append("-\n");
	}

	cout << ans;

	return 0;
}