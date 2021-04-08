#include <iostream>
#include "Queue.h"

using namespace std;

int main(){
	
	//---------------  Test Case 1  -------------------------
	Queue qt;
	
	qt.enqueue(5);
	qt.enqueue(4);
	qt.enqueue(3);
	qt.dequeue();
	
	cout << "There is " << qt.peek() << " at the front of the queue" << endl;
	
	qt.enqueue(2);
	qt.enqueue(1);
	qt.enqueue(0);
	qt.dequeue();
	
	cout << "There are " << qt.size() << " elements in the queue." << endl;
	qt.print();
	
	//---------------  Test Case 2  -------------------------
	Queue qt2;
	
	for(int i=0; i<11;i++)
		qt2.enqueue(i);
	
	if(qt2.isFull())
		cout << "Queue is full now" << endl;
	else
		cout << "Queue is not full yet" << endl;
	
	for(int i=0; i<11;i++)
		qt2.dequeue();
	
	if(qt2.isEmpty())
		cout << "Queue is empty now" << endl;
	else
		cout << "Queue is not empty yet" << endl;
	
	return 0;
}
