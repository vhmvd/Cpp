#ifndef StudentRecordManager_h
#define StudentRecordManager_h

#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

namespace str
{
	struct data
	{
		int id=0;
		string fname;
		string lname;
		const char* s1 = "MATH";
		int ms1=0;
		const char* s2 = "ENGLISH";
		int ms2=0;
		const char* s3 = "COMPUTER SCIENCE";
		int ms3=0;
		const char* s4 = "URDU";
		int ms4=0;
		const char* s5 = "PHYSICS";
		int ms5=0;
	};
}

class StudentRecordManager
{
private:
protected:
	void loadFile();
};

class records :public StudentRecordManager
{
private:
	int choice;
	bool flag;
	str::data temp;
	vector<str::data> vec;
public:
	records();
	void menu();
	void update();
	void searchRecord();
	void readAndDisplay();
	friend ostream& operator<<(ostream& output, const str::data& d);
};

ostream& operator<<(ostream& output, const str::data& d)
{
	output << "ID: " << d.id << endl << "Full name: " << d.fname << " " << d.lname << endl << d.s1 << " marks " << d.ms1 << endl << d.s2 << " marks " << d.ms2 << endl << d.s3 << " marks " << d.ms3 << endl << d.s4 << " marks " << d.ms4 << endl << d.s5 << " marks " << d.ms5 << endl;
	return output;
}

void StudentRecordManager::loadFile()
{
	fstream file;
	file.open("records.dat");
	if (file.good())
	{
		cout << "\nFile already exists!\n";
	}
	else
	{
		cout << "\nNew file created.\n";
		file.open("records.dat", ios::out);
		file.close();
	}
}

records::records()
{
	choice = 0;
	flag = true;
}

void records::menu()
{
	while (flag)
	{
		cout << "\n1. Create a file\n2. Enter new record\n3. Read and display all records\n4. Search a specific record\n5. EXIT\nINPUT: ";
		cin >> choice;
		if (choice == 1)
		{
			loadFile();
		}
		else if (choice == 2)
		{
			update();
		}
		else if (choice == 3)
		{
			readAndDisplay();
		}
		else if (choice == 4)
		{
			searchRecord();
		}
		else if (choice == 5)
		{
			flag = false;
		}
		else
		{
			cout << "\nInvalid choice! Try again!\n";
		}
	}
	return;
}

void records::searchRecord()
{

}

void records::update()
{
	fstream file;
	file.open("records.dat");
	if (file.good())
	{
		bool flag = true;
		cout << "\nEnter ID: ";
		cin >> temp.id;
		cout << "\nEnter first name: ";
		cin >> temp.fname;
		cout << "\nEnter last name: ";
		cin >> temp.lname;
		while (flag)
		{
			cout << "\nEnter marks for " << temp.s1 << ": ";
			cin >> temp.ms1;
			if (temp.ms1 > 100 || temp.ms1 < 0)
			{
				cout << "\nInvalid range!\n";
			}
			else
			{
				flag = false;
			}
		}
		flag = true;
		while (flag)
		{
			cout << "\nEnter marks for " << temp.s2 << ": ";
			cin >> temp.ms2;
			if (temp.ms2 > 100 || temp.ms2 < 0)
			{
				cout << "\nInvalid range!\n";
			}
			else
			{
				flag = false;
			}
		}
		flag = true;
		while (flag)
		{
			cout << "\nEnter marks for " << temp.s3 << ": ";
			cin >> temp.ms3;
			if (temp.ms3 > 100 || temp.ms3 < 0)
			{
				cout << "\nInvalid range!\n";
			}
			else
			{
				flag = false;
			}
		}
		flag = true;
		while (flag)
		{
			cout << "\nEnter marks for " << temp.s4 << ": ";
			cin >> temp.ms4;
			if (temp.ms4 > 100 || temp.ms4 < 0)
			{
				cout << "\nInvalid range!\n";
			}
			else
			{
				flag = false;
			}
		}
		flag = true;
		while (flag)
		{
			cout << "\nEnter marks for " << temp.s5 << ": ";
			cin >> temp.ms5;
			if (temp.ms5 > 100 || temp.ms5 < 0)
			{
				cout << "\nInvalid range!\n";
			}
			else
			{
				flag = false;
			}
		}
		file.write((char*)&temp, sizeof(temp));
		file.close();
	}
	else
	{
		cout << "\nFile does not exist. Create a new file!\n";
	}
}

void records::readAndDisplay()
{
	fstream file;
	file.open("records.dat");
	if (file.good())
	{
		while (!file.eof())
		{
			file.read((char*)&temp, sizeof(temp));
			cout << temp << endl;
		}
		file.close();
	}
	else
	{
		cout << "\nFile does not exist!\n";
		return;
	}
}

#endif
