#include <stdio.h>
#include <iostream>
#include <regex>
#include <vector>
#include "avl.hpp"
using namespace std;
#define IS_ROOT 0
#define IS_LEFT 1
#define IS_RIGHT 2
// global
vector<string> inputs;
vector<int> values;
bool balance(AvlNode *& node);
int max(int a, int b);
int height(AvlNode* node);
/**
* Internal method to insert into a subtree.
* x is the item to insert.
* t is the node that roots the subtree.
* Set the new root of the subtree.
*/
// change this to a node function to allow assignment from the result to a node variable
AvlNode* insert(int & info, AvlNode * & root ){
std::cout << "As of now, I am implementing a dummy insert" << endl;
std::cout << "Code for inserting " << info << " goes here" << endl;
AvlNode* node = root;
string input = inputs.back();
inputs.pop_back();
info = values.back();
values.pop_back();
if (input == "|l_"){
values.push_back(info);
inputs.push_back("root");
root->left = insert( info, root->left );
  
} else if(input == "|r_"){
values.push_back(info);
inputs.push_back("root");
root->right = insert( info, root->right );
  
} else if(input == "root"){
info = stoi(input, nullptr, 10);
root = new AvlNode (info, NULL, NULL);
node = root;
}
  
  
// if (root == NULL)
// root = new AvlNode (info, NULL, NULL);
// else if (info < root->element){
// root->left = insert( info, root->left );
// } else {
// root->right = insert( info, root->right );
// }
  
root->height = max(height(root->left), height(root->right)) + 1; //get the height of the tree
// if( balance(root) )
// std::cout << "true" << endl;
// else
// std::cout << "false" << endl;
return root;
}
// find height
int height(AvlNode* node){ // needed because the you can acces the height of a null node(doesn't exist)
if(node == NULL) // if the node is null exit
return 0; // return 0
else // otherwise
return node->height; // return height
}
// find the maximum of the two integers
int max(int a, int b){
return (a > b) ? a : b;
}
// balnce the avl tree
bool balance(AvlNode *& node){
if (node == NULL)
return true;/NULL root/
  
if(height(node->left) - height(node->right) > 1){ // if height of the left is larger with a diference greater than 1
return false;
} else if(height(node->right) - height(node->left) > 1){ // if the height of the right is larger with a difference greater than 1
return false;
} else
return true;
}
/*
* Print methods, do not change
*/
void print(AvlNode *root, int level, int type) {
if (root == NULL) {
return;
}
if (type == IS_ROOT) {
std::cout << root -> element << "\n";
} else {
for (int i = 1; i < level; i++) {
std::cout << "| ";
}
if (type == IS_LEFT) {
std::cout << "|l_" << root -> element << "\n";
} else {
std::cout << "|r_" << root -> element << "\n";
}
}
if (root -> left != NULL) {
print(root -> left, level + 1, IS_LEFT);
}
if (root -> right != NULL) {
print(root -> right, level + 1, IS_RIGHT);
}
}
void print(AvlNode *root) {
print(root, 0, IS_ROOT);
}
/*
* END Print methods, do not change
*/

/*
* Main method, do not change
*/
int main(int argc, const char * argv[]) {
AvlNode* root = NULL;
int level;
regex integer ("[[:digit:]]+");
std::string filename = argv[1];
freopen(filename.c_str(), "r", stdin);
std::string input;
int data;
while(std::cin >> input){
if (input == "|l_" || input == "|r_"){
std::cin>>data;
inputs.push_back(input);
values.push_back(data);
  
} else if(input == "|"){
level++;
  
} else if(regex_match(input, integer)){
data = stoi(input, nullptr, 10);
inputs.push_back("root");
values.push_back(data);
} else if(input == "print"){
print(root);
std::cout << "\n";
} else{
std::cout<<"Data not consistent in file" << endl;
return 0;
}
}
data = 0;
insert(data, root);
  
if( balance(root) )
std::cout << "true" << endl;
else
std::cout << "false" << endl;
return 0;
}
/*
* END main method
*/