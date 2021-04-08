#include "Queue.h"
#include<iostream>

using namespace std;

Queue::Queue()
{
	front = 0;
	rear = 0;
	sizee = 0;
}

bool Queue::isEmpty()
{
	return sizee == 0 ? true : false;
}

bool Queue::isFull()
{
	return sizee == 10 ? true : false;
}

int Queue::size()
{
	return sizee;
}

void Queue::enqueue(int data)
{
	if (isFull())
	{
		return;
	}
	else
	{
		queue[sizee] = data;
		front = queue[0];
		rear = queue[sizee];
		sizee++;
		return;
	}
}

int Queue::dequeue()
{
	if (isEmpty())
	{
		return -1;
	}
	else
	{
		int temp = front;
		for (int i = 0; i < sizee; i++)
		{
			if (i + 1 != 10)
			{
				queue[i] = queue[i + 1];
			}
			else
			{
				queue[i] = 0;
			}
		}
		sizee--;
		front = queue[0];
		rear = queue[sizee];
		return temp;
	}
}

int Queue::peek()
{
	return front;
}

void Queue::print()
{
	for (int i = 0; i < sizee; i++)
	{
		cout << queue[i] << "\t";
	}
	cout << endl;
}