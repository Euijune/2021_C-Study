#pragma once

class Queue
{
private:
	int front;
	int rear;
	int arr[5];

public:
	Queue();
	~Queue();
	bool isEmpty();
	bool isFull();
	void enqueue(int val);
	int dequeue();
	int count();
	void display();
};