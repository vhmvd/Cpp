#include "LinkedList.h"

Student::Student()
{
	next = NULL;
	ID = "";
	name = "";
	major = "";
}

Classroom::Classroom()
{
	head = NULL;
}

void Classroom::addStudent(string id, string name, string major)
{
	if (head == NULL)
	{
		head = new Student;
		head->ID = id;
		head->major = major;
		head->name = name;
	}
	else
	{
		Student* temp;
		if (head->next == NULL)
		{
			if (name > head->name)
			{
				temp = head;
				temp->next = new Student;
				temp = temp->next;
				temp->ID = id;
				temp->name = name;
				temp->major = major;
			}
			else
			{
				temp = new Student;
				temp->ID = id;
				temp->name = name;
				temp->major = major;
				temp->next = head;
				head = temp;
				temp = NULL;
			}
		}
		else
		{
			if (name < head->name)
			{
				temp = new Student;
				temp->ID = id;
				temp->name = name;
				temp->major = major;
				temp->next = head;
				head = temp;
				temp = NULL;
			}
			else
			{
				temp = head;
				while (name > temp->name)
				{
					if (temp->next == NULL)
					{
						temp->next = new Student;
						temp = temp->next;
						temp->ID = id;
						temp->name = name;
						temp->major = major;
						return;
					}
					temp = temp->next;
				}
				Student* follow = head;
				while (follow->next != temp)
				{
					follow = follow->next;
				}
				follow->next = new Student;
				follow = follow->next;
				follow->ID = id;
				follow->name = name;
				follow->major = major;
				follow->next = temp;
			}
		}
	}
}

void Classroom::removeStudent(string id)
{
	if (isEmpty())
	{
		cout << "\nNo such data available.";
		return;
	}
	else
	{
		Student* temp = head;
		while (temp != NULL)
		{
			if (temp->ID == id)
			{
				if (temp == head)
				{
					head = head->next;
					delete temp;
					return;
				}
				else if (head->next == temp)
				{
					if (temp->next == NULL)
					{
						delete temp;
						head->next = NULL;
						return;
					}
					else
					{
						head->next = temp->next;
						delete temp;
						return;
					}
				}
				else
				{
					Student* temp1 = head;
					while (temp1->next != temp)
					{
						temp1 = temp1->next;
					}
					if (temp->next == NULL)
					{
						delete temp;
						temp1->next = NULL;
						return;
					}
					else
					{
						temp1->next = temp->next;
						delete temp;
						return;
					}
				}
			}
			temp = temp->next;
		}
		cout << "\nNo such data available.";
		return;
	}
}

void Classroom::print()
{
	Student* temp = head;
	if (!isEmpty())
	{
		while (temp != NULL)
		{
			cout << temp->ID << "\t\t" << temp->name << "\t\t" << temp->major << endl;
			temp = temp->next;
		}
		return;
	}
	else
	{
		cout << "\nNo such data available.";
		return;
	}
}

void Classroom::print(string id)
{
	Student* temp = head;
	while (temp != NULL)
	{
		if (temp->ID == id)
		{
			cout << "Record found!\n";
			cout << temp->ID << "\t\t" << temp->name << "\t\t" << temp->major << endl << endl;
			return;
		}
		temp = temp->next;
	}
	cout << "No such data exist!\n";
	return;
}

Student Classroom::at(int index)
{
	Student* temp = head;
	int count = 0;
	while (temp != NULL)
	{
		if (index == count)
		{
			return *temp;
		}
		count++;
		temp = temp->next;
	}
	temp = NULL;
	return *temp;
}

int Classroom::getSize()
{
	if (isEmpty())
	{
		return 0;
	}
	else
	{
		Student* temp = head;
		int count = 0;
		while (temp != NULL)
		{
			count++;
			temp = temp->next;
		}
		return count;
	}
}

bool Classroom::isEmpty()
{
	if (head)
	{
		return false;
	}
	else
	{
		return true;
	}
}