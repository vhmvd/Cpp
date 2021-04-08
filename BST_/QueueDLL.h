// A Queue class based on a DLL implementation.
// Work in this implementation is delegated to a DLList object.
// A queue can be implemented as a linked list by adding to one end and deleting from
// the other end. For example, AddToTail + DeleteHead or AddToHead + DeleteTail.
// DeleteTail should be avoided with singly linked lists.

#ifndef DLL_HEADER_FILE
#include "DLL.h"
#endif
template <class T>
class QueueDLL
{
public:
	QueueDLL();
	~QueueDLL();

	void enq(T& val);	// Adds an element to the queue.
	T deq();			// Returns and removes from the queue the first element added to the queue.
	T getFirst();		// Returns the first element added to the queue.
	T getLast();		// Returns the last element added to the queue.
	bool isEmpty();
	void clearAll();
	void print();

private:
	DLL<T> list;
};

// Constructor: Automatically calls the constructor of the DLList.
template <class T>
QueueDLL<T>::QueueDLL(void){}

// Destructor: Automatically calls the destructor of the DLList.
template <class T>
QueueDLL<T>::~QueueDLL(void){}

template <class T>
T QueueDLL<T>::getFirst(){	return list.getHead();}

template <class T>
T QueueDLL<T>::getLast(){	return list.getTail();}

template <class T>
bool QueueDLL<T>::isEmpty(void){	return list.isEmpty();}

template <class T>
void QueueDLL<T>::print(){	list.print();}

template <class T>
void QueueDLL<T>::clearAll() { 	list.clearAll();}

template <class T>
void QueueDLL<T>::enq(T& el){	list.addtoTail(el);}

template <class T>
T QueueDLL<T>::deq(){
	T el = list.getHead();
	list.delHead();
	return el;
}


