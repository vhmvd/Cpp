#include <stdio.h>
#include <iostream>
#include "avl.hpp"
using namespace std;
#define IS_ROOT 0
#define IS_LEFT 1
#define IS_RIGHT 2
void balance(AvlNode *&node);
int max(int a, int b);
int height(AvlNode *node);
/**
* Internal method to insert into a subtree.
* x is the item to insert.
* t is the node that roots the subtree.
* Set the new root of the subtree.
*/
// change this to a node function to allow assignment from the result to a node variable
AvlNode *insert(const int &info, AvlNode *&root)
{
  if (root == NULL)
    root = new AvlNode(info, NULL, NULL);
  else if (info < root->element)
  {
    root->left = insert(info, root->left);
  }
  else
  {
    root->right = insert(info, root->right);
  }
  root->height = max(height(root->left), height(root->right)) + 1; //get the height of the tree
  balance(root);                                                   // balance tree after iinsertion
  return root;
}
/**
* Internal method to remove from a subtree.
* info is the item to remove.
* root is the node that roots the subtree.
* Set the new root of the subtree.
*/
void remove(const int &info, AvlNode *&root)
{
  AvlNode *removal = root;                      // initialize removal node
  AvlNode *parent = new AvlNode(0, NULL, NULL); //initialize tracks parent of removal
  int type;                                     //relationship between parent and removal

  if (root == NULL)
    return;

  while (removal->element != info)
  { //find the removal node with the right key
    if (removal == NULL)
      return; //never found/

    parent = removal; // set parent to the previous removal node
    if (info < removal->element)
    { // go left if node is bigger
      removal = removal->left;
      type = IS_LEFT;
    }
    else
    { // go right
      removal = removal->right;
      type = IS_RIGHT;
    }
  }

  if (info == removal->element)
  {

    while (removal->right != NULL && removal->left != NULL)
    { // node has both left and right child

      parent = removal;                   //go to the removal child of parent
      removal = removal->left;            //go to left of the romoval node
      parent->element = removal->element; // update the removal element
      type = IS_LEFT;
    }

    if (removal->right == NULL && removal->left != NULL)
    { // if node has a left child

      if (type == IS_LEFT)
      {
        parent->left = removal->left;
      }
      else
      {
        parent->right = removal->left;
      }
    }
    else if (removal->left == NULL && removal->right != NULL)
    { // if node has a right child
      cout << "test" << endl;
      if (type == IS_LEFT)
      {
        parent->left = removal->right;
      }
      else
      {
        parent->right = removal->right;
      }
    }
    else if (removal->left == NULL && removal->right == NULL)
    { //if node has no child
      if (type == IS_LEFT)
      {
        parent->left = NULL;
      }
      else
      {
        parent->right = NULL;
      }
    }
    else
      std::cout << "error" << endl;
  }
  balance(root); // balance tree after deletion
}
/*
* You will probably neesd auxiliary mathods to
* - find the minimum of tree
* - rotate (single and double, in both directions
* - balance am AVL tree
*/
// find height
int height(AvlNode *node)
{                        // needed because the you can acces the height of a null node(doesn't exist)
  if (node == NULL)      // if the node is null exit
    return 0;            // return 0
  else                   // otherwise
    return node->height; // return height
}
// find the maximum of the two integers
int max(int a, int b)
{
  return (a > b) ? a : b;
}
// find the minimum
int minimum(AvlNode *&root)
{
  while (root->left != NULL)
  {
    root = root->left;
  }
  return root->element;
}
// right rotate single
AvlNode *rotateRight(AvlNode *&node)
{
  AvlNode *leftchild = node->left;
  // rotate with the left child
  node->left = leftchild->right;
  leftchild->right = node;
  //update height
  node->height = max(height(node->left), height(node->right)) + 1;
  leftchild->height = max(height(leftchild->left), height(leftchild->right)) + 1;
  // update node
  node = leftchild;
  return node;
}
// left rotate single
AvlNode *rotateLeft(AvlNode *&node)
{
  AvlNode *rightchild = node->right;
  // rotate with the right child
  node->right = rightchild->left;
  rightchild->left = node;
  // update height
  node->height = max(height(node->left), height(node->right)) + 1;
  rightchild->height = max(height(rightchild->left), height(rightchild->right)) + 1;
  //update node
  node = rightchild;
  return node;
}
// double right rotate
void doubleRight(AvlNode *&node)
{
  node->left = rotateLeft(node->left);
  node = rotateRight(node);
}
// double left rotate node
void doubleLeft(AvlNode *&node)
{
  node->right = rotateRight(node->right);
  node = rotateLeft(node);
}
// balnce the avl tree
void balance(AvlNode *&node)
{
  if (node == NULL)
    return; //NULL root/

  if (height(node->left) - height(node->right) > 1)
  {                                                            // if height of the left is larger with a diference greater than 1
    if (height(node->left->left) >= height(node->left->right)) //balance left/ // left child of the left node is greater
      rotateRight(node);                                       // single right rotate
    else                                                       // otherwise
      doubleRight(node);                                       // double right rotate
  }
  else if (height(node->right) - height(node->left) > 1)
  {                                                              // if the height of the right is larger with a difference greater than 1
    if (height(node->right->right) >= height(node->right->left)) //balance right/ // right child of the right node is greater
      rotateLeft(node);                                          // single left rotate
    else                                                         // otherwise
      doubleLeft(node);                                          // double left rotate
  }
}

/*
* Print methods, do not change
*/
void print(AvlNode *root, int level, int type)
{
  if (root == NULL)
  {
    return;
  }
  if (type == IS_ROOT)
  {
    std::cout << root->element << "\n";
  }
  else
  {
    for (int i = 1; i < level; i++)
    {
      std::cout << "| ";
    }
    if (type == IS_LEFT)
    {
      std::cout << "|l_" << root->element << "\n";
    }
    else
    {
      std::cout << "|r_" << root->element << "\n";
    }
  }
  if (root->left != NULL)
  {
    print(root->left, level + 1, IS_LEFT);
  }
  if (root->right != NULL)
  {
    print(root->right, level + 1, IS_RIGHT);
  }
}
void print(AvlNode *root)
{
  print(root, 0, IS_ROOT);
}
/*
* END Print methods, do not change
*/

/*
* Main method, do not change
*/
int main(int argc, const char *argv[])
{
  AvlNode *root = NULL;
  std::string filename = argv[1];
  freopen(filename.c_str(), "r", stdin);
  std::string input;
  int data;
  while (std::cin >> input)
  {
    if (input == "insert")
    {
      std::cin >> data;
      std::cout << "inserting " << data << endl;
      insert(data, root);
    }
    else if (input == "delete")
    {
      std::cin >> data;
      std::cout << "deleting " << data << endl;
      remove(data, root);
    }
    else if (input == "print")
    {
      print(root);
      std::cout << "\n";
    }
    else
    {
      std::cout << "Data not consistent in file";
      break;
    }
  }
  return 0;
}
/*
* END main method
*/