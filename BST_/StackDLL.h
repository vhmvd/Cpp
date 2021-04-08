// A Stack class based on a DLL implementation
// If a singly linked list is used, addition and deletion should be done at the
// head. This is because DeleteTail is O(n), whereas DeleteHead is O(1).
#ifndef DLL_HEADER_FILE
#include "DLL.h"
#endif


template <class T>
class StackDLL
{
public:
	StackDLL();
	~StackDLL();

	void push(T& el);	// Adds an element to the stack
	T pop(void);		// Returns and Removes the last added element.
	T top(void);		// Returns the last added element.
	bool isEmpty(void);	
	void clear(void);

private:
	DLL<T> list;
};


// Constructor.
// Automatically calls the constructor of the DLList.
template <class T>
StackDLL<T>::StackDLL(void){}

// Destructor.
// Automatically calls the destructor of the DLList.
template <class T>
StackDLL<T>::~StackDLL(void){}

template <class T>
void StackDLL<T>::push(T& el)
{
	list.addToTail(el);
}

template <class T>
T StackDLL<T>::pop()
{
	T el = list.getTail();
	list.removeTail();
	return el;
}

template <class T>
T StackDLL<T>::top()
{
	return list.getTail();
}

template <class T>
bool StackDLL<T>::isEmpty(void)
{
	return list.isEmpty();
}

template <class T>
void StackDLL<T>::clear(void)
{
	list.clearn();
}
