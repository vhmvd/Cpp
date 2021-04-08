#ifndef Queue_h
#define Queue_h
#define MAX 10

class Queue
{
private:
	int front;
	int rear;
	int sizee;
	int queue[MAX];
public:
	Queue();
	bool isEmpty();
	bool isFull();
	int size();
	void enqueue(int);
	int dequeue();
	int peek();
	void print();
};

#endif // !Queue_h