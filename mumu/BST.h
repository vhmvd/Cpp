#include <string>
#include <iostream>
using namespace std;

//Binary Search Tree Class
//Contains Declarations 

class BST {
private:
	//Node Class which acts as an element(word) in the dictionary
	//Contains Data, Along with pointers for its left and right
	//Left pointer contains an element (alphabetically) smaller than element (data)
	//Right pointer contains an element (alphabetically) greater than element (data)
	class node {
	public:
		string data;
		node* left;
		node* right;
		//constructor for node
		node(string ch) : data(ch), left(nullptr), right(nullptr) {}

	};
	//Root is the base node of BST (i.e. Starting Point of BST)
	node* root;//pointer to the root

	static void visit_inorder(const node*, void(*)(string)); // Function to visit all nodes in BST in order(alphabetical order)
	static void insert(node*& n, string data); //(Function to insert data in node of BST)

public:
	//constructor
	BST();
	//Function to insert data in BST
	void insert(string data);
	// call a function for each element.
	void visit_inorder(void(*f)(string)) const { visit_inorder(root, f); }// Function to visit the BST in order(alphabetical order)
	void Search(string d);//Function to Search for an element in BST
};
