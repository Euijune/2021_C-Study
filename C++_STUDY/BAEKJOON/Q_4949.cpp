#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalance(string str) {
	stack<char> stack;
	stack.push('_');	//

	for (char elem : str) {
		if (elem == '(')
			stack.push('(');
		else if (elem == '[')
			stack.push('[');
		else if (elem == ')')
			if (!stack.empty() && stack.top() == '(')
				stack.pop();
			else
				return false;
		else if (elem == ']')
			if (!stack.empty() && stack.top() == '[')
				stack.pop();
			else
				return false;
	}
	stack.pop();	//

	return stack.empty();
}

int main() {
	while (true) {
		string sentence;
		getline(cin, sentence);

		if (sentence == ".")
			break;

		bool is_balanced = isBalance(sentence);

		if (is_balanced)
			cout << "yes\n";
		else
			cout << "no\n";
	}

	return 0;
}