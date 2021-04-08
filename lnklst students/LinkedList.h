#ifndef LNKDLST_h
#define LNKDLST_h

#include<string>
#include<iostream>

using namespace std;

class Student
{
public:
	string ID;
	string name;
	string major;
	Student* next;
	Student();
};

class Classroom
{
	Student* head;
public:
	Classroom();
	void addStudent(string, string, string);
	void removeStudent(string);
	void print();
	void print(string);
	Student at(int);
	int getSize();
	bool isEmpty();
};

#endif // !LNKDLST_h

