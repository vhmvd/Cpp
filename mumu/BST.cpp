#include <string>
#include <iostream>
#include "BST.h"
using namespace std;

BST::BST() : root(nullptr) {}// BST constructor(default)


//Insert functon
void BST::insert(BST::node*& n, string data)
{
	//Checks if data is alphabetically  smaller than node
	
	if (data < n->data)
	{
		//If true and if there is another element already present on the left, then recur until a correct position is found
		if (n->left)
			insert(n->left, data);

		//When reaches a node where no further element exsists beyond that node, then insert it there
		else
			n->left = new node(data);
	}
	//Checks if data is alphabetically  greater than node
	else if (data > n->data)
	{
		//If true and if there is another element already present on the right, then recur until a correct position is found
		if (n->right)
			insert(n->right, data);
		//When reaches a node where no further element exsists beyond that node, then insert it there
		else
			n->right = new node(data);
	}
}

//insert helper function that is used in recursion logic used above
void BST::insert(string data)
{
	//If tree is empty, insert element on root node
	if (root == nullptr)
		root = new node(data);
	//If not recur until an empty node is found
	else
		insert(root, data);
}

//Function to visit tree in order
void BST::visit_inorder(const BST::node * n, void(*func)(string))
{
	//If node is empty or an end node is found, return
	if (!n)
		return;
	//else recur to the left of node, when an end is reached on the left of nodes, extract its data, then recur for right of nodes and extract its data
	//In this way we are starting at the very bottom and going left, right and up
	//This left right & up strategy is what is getting us all the elements in a sorted alphabetical order
	//Note that this function does not sorts the tree, all elements in the tree are sorted, the moment an element is enterd in the tree
	//This function just outputs that sorted tree
	visit_inorder(n->left, func);
	func(n->data);
	visit_inorder(n->right, func);
}


//Function to search for a pirticular an element in the tree 
void BST::Search(string d)
{
	int depth = 0;
	node* temp;// = new node;
	temp = root;//start at root

	//Strings used for parsing
	string datasort, deli, token;
	deli = ":";
	
	while (temp != NULL) {
		depth++;


		datasort = temp->data;
		token = datasort.substr(0, datasort.find(deli));//token contains the word in the dictionary

		//If found Print at what depth of tree it was found and its definition as well
		if (token == d)
		{
			cout << "\nItem found at depth: " << depth << endl;
			cout << "Definition is: " << datasort << endl;
			return;
		}
		//If not found at current depth, recur to left if it was smaller than current node
		else if (temp->data > d)
			temp = temp->left;

		//Recur to right if it was greater than current node
		else
			temp = temp->right;
	}
	//If not found in the entire tree, Print a message
	cout << "\nItem not found";
	return;
}