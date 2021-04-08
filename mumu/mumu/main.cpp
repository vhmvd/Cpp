#include <string>
#include <iostream>
#include <fstream>
#include <time.h>
#include <chrono>
#include "MapADT.h"
#include "BST.h"
#include <thread>
#include <mutex>
#include <cstdlib>
using namespace std;
using namespace std::chrono;
//Simple printing Function that gets a string and prints it
void print_element(string element)
{
	std::cout << element << '\n';
}
mutex mtx;
void bstInsert(BST& bst, string& words) {
	mtx.lock();
	bst.insert(words);
	mtx.unlock();
}

void bstsearch(BST& bst, string& n) {
	auto start = std::chrono::high_resolution_clock::now();
	bst.Search(n);////Call search function
	auto elapsed = std::chrono::high_resolution_clock::now() - start;
	long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
	cout << "Time taken to find in BST is: " << std::to_string(microseconds) << " milliseconds" << endl;
}

void mapInsert(MapADT& map, string &token,string& words) {
	mtx.lock();
	map.insert(token, words);
	mtx.unlock();
}

void mapsearch(MapADT& map, string& n) {
	//If input string is not found, print error message
	auto start = std::chrono::high_resolution_clock::now();
	if (map.find(n) == "")
	{
		cout << "Word Not Found!" << endl;
	}
	//else display 
	else
	{
		cout << map.find(n);
		auto elapsed = std::chrono::high_resolution_clock::now() - start;
		long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
		cout << "Time taken to find in map is: " << std::to_string(microseconds) << " milliseconds" << endl;
	}
}

int main()
{
	fstream myfile;
	string words;
	int a = 1;
	while (a < 5) {
		//Opening File
		myfile.open("file"+std::to_string(a)+".txt");
		if (myfile.is_open())
		{
			int count = 0;
			BST bst;//BST object creation
			long totalTimeTakenBST = 0;
			MapADT map;
			long totalTimeTakenMap = 0;
			string deli, token;
			deli = ":";

			while (!myfile.eof())//Loop till the end of file
			{
				//Getting data from file and inserting it into the tree
				getline(myfile, words);
				string words1 = words;
				token = words1.substr(0, words1.find(deli));//Parsing data(Separating words from their definitions)
				thread threadBSTObj(&bstInsert, std::ref(bst), std::ref(words));
				thread threadMAPObj(&mapInsert, std::ref(map),std::ref(token), std::ref(words)); 
				map.insert(token, words1);//Inserting words and their definitions into the map

				threadBSTObj.join();
				threadMAPObj.join();
				count++;
			}

			cout << "All Words Entered!\n";
			string n;
			//Prompting user to search
		here:
			cout << "Enter the Element to be searched:\n";
			getline(cin, n);//Get string
			thread threadBSTObj(&bstsearch, std::ref(bst), std::ref(n));
			thread threadMAPObj(&mapsearch, std::ref(map), std::ref(n));
			threadBSTObj.join();
			threadMAPObj.join();
			cout << "\n\nDo you want to search again...enter choice(y/n)?\t";
			string ch;
			//cin.ignore();
			getline(cin, ch);//Ask choice to search again
			if (ch == "y" || ch == "Y")
				goto here;//if yes rerun this part

			cout << endl;
		}
		else//if file not opened print error message
		{
			cout << "\nProblem in opening file\n";
		}


		myfile.close();//close the file
		a++;
	}



	system("pause");

	return 0;
}