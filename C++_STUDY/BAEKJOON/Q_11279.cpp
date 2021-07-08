#include <queue>
#include <stdio.h>

using namespace std;

class comp {
public:
	bool operator()(int& left, int& right)const {
		return left < right; // 내림차순
	}
};

int main() {


	priority_queue<int, vector<int>, comp> arr; // 오름차순
	int task, cmd;
	scanf_s("%d", &task);

	for (int i = 0; i < task; i++) {
		scanf_s("%d", &cmd);
		if (cmd == 0) {
			if (arr.empty())
				printf("%d\n", 0);
			else {
				printf("%d\n", arr.top());
				arr.pop();
			}
		}
		else
			arr.push(cmd);
	}

	return 0;
}