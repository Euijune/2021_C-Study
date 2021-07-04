#include <iostream>
#include <string>
#include <stack>
using namespace std;


void callCommand(stack<int>& s, string str) {
	if (str == "push") {
		int x;
		cin >> x;
		s.push(x);
	}
	else if (str == "pop")
	{
		if (s.empty())	cout << -1 << endl;
		else
		{
			int elem;
			elem = s.top();
			s.pop();
			cout << elem << endl;
		}
		
	}
	else if (str == "size")	cout << s.size() << endl;
	else if (str == "empty")cout << s.empty() << endl;
	else if (str == "top")
	{
		if (s.empty())	cout << -1 << endl;
		else
		{
			cout << s.top() << endl;
		}
	}
}

int main() {

	string str;
	int n;
	stack<int> s;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str;
		callCommand(s, str);
	}

	return 0;
}