#include <string>
#include <iostream>
#include "MapADT.h"
using namespace std;

//Constuctor/Memory Allocator for map
MapADT::MapADT() 
{
	//Initializes each key and value as a string 
	for (int i = 0; i < size_max; i++) {
		keys[i] = string();
		values[i] = string();
	}
}

//Hash Function
//Note that this could be any random number to create hash(eg. here 37 is used)
//Each index in the value array gets assigned a hash number/index
unsigned int MapADT::hash(const string& k)
{
	unsigned int value = 0;
	for (int i = 0; i < k.length(); i++)
		value = 37 * value + k[i];
	return value;
}

//Printing function for map
//Until the array of keys is empty, Print all its values
//Here Keys are Words, and Values are Definitions
void MapADT::print() {

	for (int i = 0; i < size_max; i++)
		if (!keys[i].empty())
			cout << values[i] << endl;

}

//Finding a hash index function
int MapADT::find_index(const string & key, bool override_duplicate_key = true) {
	unsigned int h = hash(key) % size_max, offset = 0, index;
	// empty index for new entry with key or find the index of key in hash table
	// if override_duplicate_key is true, return an empty place
	// if `override_duplicate_key` is `false`, return a new, unused index
	while (offset < size_max) {
		index = (h + offset) % size_max;

		if (keys[index].empty() ||
			(override_duplicate_key && keys[index] == key))
			return index;

		offset++;
	}
	return -1;
}

//insert a new key and a value function
void MapADT::insert(const string & key, const string & value) {
	int index = find_index(key);
	//if table is full, Print an error message
	if (index == -1) {
		cerr << "Table is full!" << endl;
		return;
	}
	//else insert the values
	keys[index] = key;
	values[index] = value;
}


//Function to find a key given by user
string MapADT::find(const string & key) {
	int index = find_index(key);//get hash indeex
	if (index != -1)
		return values[index];//returns values of index

	return "";//else returns an empty string
}
