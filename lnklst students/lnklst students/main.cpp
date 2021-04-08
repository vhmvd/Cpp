#include"LinkedList.h"

int main()
{
	Classroom stu;
	stu.addStudent("A25123", "Izzie Cline", "Mathematics");
	stu.addStudent("A23452", "Bridget McCann", "Computer Science");
	stu.addStudent("A45120", "Isa Powell", "History");
	stu.addStudent("A56009", "Nick Miller", "Computer Science");
	stu.addStudent("A65980", "Alannah Wilks", "Literature");
	stu.addStudent("A45018", "Montana Gates", "Biology");
	stu.addStudent("A86003", "Janet Newman", "Nursing");
	stu.print();
	stu.removeStudent("A86003");
	stu.print("A86003");
	stu.print();
}