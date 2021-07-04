#include "queue.h"
#include <iostream>
#include <string>
using namespace std;

Queue::Queue()
{
	front = -1;
	rear = -1;
	for (int i = 0; i < 5; i++) {
		arr[i] = 0;
	}
}

Queue::~Queue() {};

bool Queue::isEmpty()
{
	if (front == -1 && rear == -1)
		return true;
	else
		return false;
}

bool Queue::isFull() 
{
	if (rear == 4) // max index = 5
		return true;
	else
		return false;
}

void Queue::enqueue(int val)
{
	if (isFull())
	{
		cout << "Queue Full" << endl;
	}
	else if (isEmpty())
	{
		rear = 0;
		front = 0;
		arr[rear] = val;
	}
	else
	{
		rear++;
		arr[rear] = val;
	}
}

int Queue::dequeue() 
{
	int x = 0;

	if (isEmpty())
	{
		cout << "Queue is Empty" << endl;
		return x;
	}
	else if (rear == front)
	{
		x = arr[rear];
		rear -= 1;
		front -= 1;
		return x;
	}
	else
	{
		cout << "front value: " << front << endl;
		x = arr[front];
		arr[front] = 0;
		front++;
		return x;
	}
}

int Queue::count() 
{
	return (rear - front + 1);
}

void Queue::display() {
	cout << "All values in the Queue are - " << endl;
	for (int i = 0; i < 5; i++)
		cout << arr[i] << " ";
}