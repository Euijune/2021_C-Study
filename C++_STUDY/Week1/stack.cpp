#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
	int top;
	int arr[5];

public:

	//持失切
	Stack() 
	{
		top = -1;
		for (int i = 0; i < 5; i++) 
		{
			arr[i] = 0;
		}
	}

	//社瑚切
	~Stack() {}

	bool isEmpty() 
	{
		if (top == -1)
			return true;
		else
			return false;
	}

	bool isFull() 
	{
		if (top == 4) // max index = 5
			return true;
		else
			return false;
	}

	void push(int val) 
	{
		if (isFull())
			cout << "Stack Overflow" << endl;
		else
		{
			top++;
			arr[top] = val;
		}
	}

	int pop()
	{
		if (isEmpty())
		{
			cout << "Stack Overflow" << endl;
			return 0;
		}
		else
		{
			int popValue = arr[top];
			arr[top] = 0;
			top--;
			return popValue;
		}
	}

	int count()
	{
		return (top + 1);
	}

	int peek(int pos)
	{
		if (isEmpty())
		{
			cout << "Stack Overflow" << endl;
			return 0;
		}
		else
			return arr[pos];
	}

	void change(int pos, int val) 
	{
		arr[pos] = val;
		cout << "value changed at location " << pos << endl;
	}

	void display()
	{
		cout << "All values in the Stack are " << endl;
		for (int i = 4; i > 0; i--) 
		{
			cout << arr[i] << endl;
		}
	}
};