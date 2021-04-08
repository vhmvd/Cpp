#include <string>
#include <iostream>
using namespace std;

//Implementation 2 Using Hashmaps

//Hashmap Class
//Contains Declarations 
class MapADT {
public:
	MapADT();//Default constructor

	string find(const string& key);//Search function for Map
	void insert(const string& key, const string& value);//Insert function for Map


	void print();//Print function for Map
protected:
	//Protected Data for a standard map

	//THe hash function
	unsigned int hash(const string& key);

	//The index of hashmap to be found
	int find_index(const string& key, bool override_duplicated_key);

	//Maximum Map size
	//Predefined to 100
	const static unsigned int size_max = 1000;
	//Keys and values of map (Words and Definitions)
	string keys[size_max];
	string values[size_max];
};


