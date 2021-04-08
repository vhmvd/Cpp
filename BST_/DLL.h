#pragma once
#include <iostream>
using namespace std;
template <class T>
class node {
public:
	node* prev;
	node* next;
	T value;
	node(node * p, T v, node *n) {
		prev = p;
		value = v;
		next = n;
	}
	~node() {
		cout << "node destroyed: " << value << endl;
	}
};
template <class T>
class DLL {
	node<T> * head, *tail;
public:
	DLL();
	void addToHead(T v);
	void print();
	void printReverse(); // previous pointer
	void addToTail(T v);
	void removeHead();
	void removeTail();
	void clear();
	~DLL();
	bool isEmpty();
	bool search(T v);
	void append(DLL<T> &list2);
	void insertInOrder(T v); // assuming list is sorted
	bool deleteNode(T v);
	void mergeInOrder(DLL<T> &list2);
	T getTail() {
		if (tail != NULL)
			return tail->value;
		else
			exit(0);
	}
};
#include<algorithm>
template <class T>
DLL<T>::DLL() {
	head = tail = NULL;
}
template <class T>
DLL<T>::~DLL() {
	clear();
}
template <class T>
void DLL<T>::addToHead(T v) {
	node<T>* newNode = new node<T>(NULL, v, head);
	if (head == NULL) { // empty
		head = tail = newNode;
	}
	else { // one or more than one nodes
		//newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
}
template <class T>
void DLL<T>::print() {
	node<T>* p = head;
	cout << " NULL <- ";
	while (p != NULL) {
		cout << p->value << " <=> ";
		p = p->next;
	}
	cout << " NULL " << endl;
}

template <class T>
void DLL<T>::addToTail(T v) {
	node<T> * newNode = new node<T>(tail, v, NULL);
	if (head == NULL) // isempty
	{
		head = tail = newNode;

	}
	else { // one or more nodes in the list
		tail->next = newNode;
		tail = newNode;
	}
}
template <class T>
void DLL<T>::printReverse() {
	node<T> *p = tail;
	while (p != NULL) {
		cout << p->value << " <=>";
		p = p->prev;
	}
	cout << endl;
}
template <class T>
void DLL<T>::removeHead() {
	if (head == NULL)
		return;
	if (head == tail) // one node
	{
		node<T> *todelete = head;
		delete todelete;
		head = tail = NULL;
	}
	else {
		node<T> *todelete = head; // «„”ﬂ «· head
		head = head->next; // Õ—ﬂ
		head->prev = NULL; //  “»ÿ
		delete todelete;  // «‘ÿ»
	}
}
template <class T>
void DLL<T>::removeTail() {

	node<T> *Todelete = tail;
	if (head == NULL) // empty
		return;
	if (head == tail)
	{ // one node

		head = tail = NULL;
	}
	else {
		tail = tail->prev;
		tail->next = NULL;
	}
	delete Todelete;
}
template <class T>
void DLL<T>::clear() {
	node<T> * p = head;
	while (p != NULL) {
		head = head->next;
		delete p;
		p = head;
	}
}
template <class T>
bool DLL<T>::isEmpty() {
	return head == NULL;
}

template <class T>
bool DLL<T>::search(T v) {
	node<T> *p = head;
	while (p != NULL) {
		if (p->value == v)
			return true;
		p = p->next;
	}
	return false;
}

template <class T>
void DLL<T>::append(DLL<T> &list2) {

	/*node<T> *p2 = list2.head;
	while (p2 != NULL) {
		addToTail(p2->value);
		p2 = p2->next;

	}*/
	node<T> *p2 = list2.tail;
	while (p2 != NULL) {
		addToHead(p2->value);
		p2 = p2->prev;
	}
}

template <class T>
void DLL<T>::insertInOrder(T v) {

	node<T> *newNode = new node<T>(NULL, v, NULL);
	if (isEmpty()) {
		head = tail = newNode;
	}
	else if (v < head->value) {
		addToHead(v);
	}
	else if (v > tail->value) {
		addToTail(v);
	}
	else {
		node<T> *p = head;
		while (p != NULL) {
			if (p->next->value > v) {
				newNode->next = p->next;
				newNode->prev = p;
				p->next = newNode;
				newNode->next->prev = newNode;
				break;
			}
			p = p->next;
		}
	}
}

template <class T>
bool DLL<T>::deleteNode(T v) {
	if (isEmpty())
		return false;
	if (head->value == v)
	{
		removeHead();
		return true;
	}
	if (tail->value == v)
	{
		removeTail();
		return true;
	}
	else {
		node<T> *p = head;
		bool flag = false;
		while (p != NULL)
		{
			if (p->value == v) {
				flag = true;
				break;
			}
			p = p->next;
		}
		if (flag == false)
			return false;
		else {
			p->prev->next = p->next;
			p->next->prev = p->prev;
			delete p;
			return true;
		}
	}
}

template <class T>
void DLL<T>::mergeInOrder(DLL<T> &list2) {
	DLL<T> list3;

	if (list2.isEmpty() == true)
		return;
	if (isEmpty())
	{
		append(list2);
	}
	else {
		node<T> *p1 = head;
		node<T> *p2 = list2.head;

		while (p1 != NULL || p2 != NULL) {

			if (p1 == NULL) {
				list3.addToTail(p2->value);
				p2 = p2->next;
			}
			else if (p2 == NULL) {
				list3.addToTail(p1->value);
				p1 = p1->next;
			}

			else if (p1->value <= p2->value) {
				list3.addToTail(p1->value);
				p1 = p1->next;
			}
			else if (p2->value < p1->value) {
				list3.addToTail(p2->value);
				p2 = p2->next;
			}
		}
		clear();
		head = list3.head;
		tail = list3.tail;

		list3.head = list3.tail = NULL; // very important
	}
}
