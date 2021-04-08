#include<iostream>
#include"Map.h"

using namespace std;

int main()
{
	Map<int, int> test_object;
	Put(test_object, 1, 10);
	Put(test_object, 10, 100);
	Put(test_object, 100, 1000);
	Put(test_object, 1000, 10000);

	try
	{
		cout << Get(test_object, 10) << endl;
	}catch (const char* msg)
	{
		cerr << msg;
	}

	try
	{
		cout << Get(test_object, 3534) << endl;
	}catch (const char* msg)
	{
		cerr << msg;
	}

	try
	{
		cout << Get(test_object, 1000) << endl;
	}catch (const char* msg)
	{
		cerr << msg;
	}

	Remove(test_object, 10);

	try
	{
		cout << Get(test_object, 10) << endl;
	}catch (const char* msg)
	{
		cerr << msg;
	}
}