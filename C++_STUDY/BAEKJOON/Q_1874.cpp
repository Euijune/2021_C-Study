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

		if (i == 0) { // �� ó�� stack ������ ����ִ� �����϶�
			seq.push(1);
			ans.append("+\n");
		}

		while (x != (seq.empty() ? -1 : seq.top())) { // ���� �߰��� stack�� ������ ��� ��� ����
			if (x < (seq.empty() ? -1 : seq.top())) { // NO�� ��µǴ� ����
				ans = "NO";
				endflag = 1; // while �ٱ� for�� break
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