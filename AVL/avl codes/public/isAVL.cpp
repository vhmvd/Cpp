#include <stdio.h>
#include <iostream>
#include "avl.hpp"
using namespace std;
#define IS_ROOT 0
#define IS_LEFT 1
#define IS_RIGHT 2
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
AvlNode* insert( const int & info, AvlNode * & root ){
std::cout << "As of now, I am implementing a dummy insert" << endl;
std::cout << "Code for inserting " << info << " goes here" << endl;
if (root == NULL)
root = new AvlNode (info, NULL, NULL);
else if (info < root->element){
root->left = insert( info, root->left );
} else {
root->right = insert( info, root->right );
}
  
root->height = max(height(root->left), height(root->right)) + 1; //get the height of the tree
// if( balance(root) )
// std::cout << "true" << endl;
// else
// std::cout << "false" << endl;
return root;
}
/**
* Internal method to remove from a subtree.
* info is the item to remove.
* root is the node that roots the subtree.
* Set the new root of the subtree.
*/
void remove( const int & info, AvlNode * & root ) {
std::cout << "Code for deleting " << info << " goes here" << endl;
  
AvlNode *removal = root; // initialize removal node
AvlNode *parent = new AvlNode (0, NULL, NULL); //initialize tracks parent of removal
int type; //relationship between parent and removal
  
if(root == NULL)
return;
  
while(removal->element != info){ //find the removal node with the right key
if(removal == NULL)
return; /never found/
  
parent = removal; // set parent to the previous removal node
if(info < removal->element){ // go left if node is bigger
removal = removal->left;
type = IS_LEFT;
} else { // go right
removal = removal->right;
type = IS_RIGHT;
}
}
  
if(info == removal->element){
  
while (removal->right != NULL && removal->left != NULL){ // node has both left and right child
  
parent = removal; //go to the removal child of parent
removal = removal->left; //go to left of the romoval node
parent->element = removal->element; // update the removal element
type = IS_LEFT;
  
}
  
  
if(removal->right == NULL && removal->left != NULL){ // if node has a left child
  
if(type == IS_LEFT){
parent->left = removal->left;
} else{
parent->right = removal->left;
}
  
} else if(removal->left == NULL && removal->right != NULL){ // if node has a right child
cout << "test" << endl;
if (type == IS_LEFT){
parent->left = removal->right;
} else{
parent->right = removal->right;
}
  
} else if(removal->left == NULL && removal->right == NULL){ //if node has no child
if (type == IS_LEFT){
parent->left = NULL;
} else{
parent->right = NULL;
}
  
} else
std::cout << "error" << endl;
  
}
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
AvlNode *root = NULL;
std::string filename = argv[1];
freopen(filename.c_str(), "r", stdin);
std::string input;
int data;
while(std::cin >> input){
if (input == "insert"){
std::cin>>data;
insert(data, root);
} else if(input == "delete"){
std::cin>>data;
remove(data, root);
} else if(input == "print"){
print(root);
std::cout << "\n";
} else{
std::cout<<"Data not consistent in file";
break;
}
}
if( balance(root) )
std::cout << "It is an Avl" << endl;
else
std::cout << "Not an Avl" << endl;
return 0;
}
/*
* END main method
*/
