#include <iostream>
#include <stack>

int* S;
int k;

void find(int indx, std::stack<int> s) {
	if (indx == k) {
		return;
	}
	
	s.push(S[indx]);
	if (s.size() == 6) {
		std::stack<int> temp;

		while (!s.empty()) {
			temp.push(s.top());
			s.pop();
		}
		while (!temp.empty()) {
			std::cout << temp.top() << " ";
			s.push(temp.top());
			temp.pop();
		}
		std::cout << '\n';

		s.pop();
		find(indx + 1, s);
	}
	else {
		find(indx + 1, s);
		s.pop();
		find(indx + 1, s);
	}	
}

int main() {
	// For fast I/O
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	do {
		std::stack<int> s;
		std::cin >> k;
		S = new int[k];

		for (int i = 0; i < k; i++)
			std::cin >> S[i];

		find(0, s);
		std::cout << '\n';

	} while (k != 0);

	return 0;
}