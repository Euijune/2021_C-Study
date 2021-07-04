#include "stack.h"
#include <iostream>
#include <string>
using namespace std;

Stack::Stack()
{
	top = -1;
	for (int i = 0; i < 5; i++)
	{
		arr[i] = 0;
	}
}

Stack::~Stack() {}

bool Stack::isEmpty()
{
	if (top == -1)
		return true;
	else
		return false;
}

bool Stack::isFull()
{
	if (top == 4) // max index = 5
		return true;
	else
		return false;
}

void Stack::push(int val)
{
	if (isFull())
		cout << "Stack Overflow" << endl;
	else
	{
		top++;
		arr[top] = val;
	}
}

int Stack::pop()
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

int Stack::count()
{
	return (top + 1);
}

int Stack::peek(int pos)
{
	if (isEmpty())
	{
		cout << "Stack Overflow" << endl;
		return 0;
	}
	else
		return arr[pos];
}

void Stack::change(int pos, int val)
{
	arr[pos] = val;
	cout << "value changed at location " << pos << endl;
}

void Stack::display()
{
	cout << "All values in the Stack are " << endl;
	for (int i = 4; i >= 0; i--)
	{
		cout << arr[i] << endl;
	}
}

