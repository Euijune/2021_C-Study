// 강의자료 11페이지부터 보면서 do while문 만들어보자.
// class 정렬 가능하면 정리해보자. Day0의 car class처럼.

#include "stack.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	Stack sl;
	int operation, position, value;

	do
	{
		cout << "What operation do you want to perform? Select Option number, Enter 0 to exit. " << endl;
		cout << "1. Push() " << endl;
		cout << "2. POP() " << endl;
		cout << "3. isEmpty() " << endl;
		cout << "4. isFull() " << endl;
		cout << "5. Peek() " << endl;
		cout << "6. count() " << endl;
		cout << "7. change() " << endl;
		cout << "8. display() " << endl;
		cout << "9. Clear Screen " << endl << endl;

		cin >> operation;
		switch (operation)
		{
		case 0:
			break;

		case 1:
			cout << "Enter an item to push in the stack " << endl;
			cin >> value;
			sl.push(value);
			break;

		case 2:
			cout << "POP Function Called - Poped value: " << sl.pop() << endl;
			break;

		case 3:
			if (sl.isEmpty())
				cout << "Stack is Empty " << endl;
			else
				cout << "Stack is not Empty " << endl;
			break;

		case 4:
			if (sl.isFull())
				cout << "Stack is Full " << endl;
			else
				cout << "Stack is not Full " << endl;
			break;

		case 5:
			cout << "Enter position of item you want to peek: " << endl;
			cin >> position;
			cout << "Peek Function Called - Value at Position " << position << " is " << sl.peek(position) << endl;
			break;

		case 6:
			cout << "Count Function Called - Number of Items in the Stack are: " << sl.count() << endl;
			break;

		case 7:
			cout << "Change Function Called - " << endl;
			cout << "Enter Position of item you want to change : ";
			cin >> position;
			cout << endl;
			cout << "Enter value of item you want to change: ";
			cin >> value;
			sl.change(position, value);
			break;

		case 8:
			cout << "Display Function Called - " << endl;
			sl.display();
			break;

		case 9:
			system("cls");
			break;

		default:
			cout << "Enter Proper Option number " << endl;
		}
	} while (operation != 0);

	return 0;
}