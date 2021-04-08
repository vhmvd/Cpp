// A binary search tree (BST) class to store elements of a generic type T

#include "QueueDLL.h"
#include "StackDLL.h"
#include <iostream>
#include<vector>
using namespace std;

int MAX(int, int);

template <class T>
class BST;

template <class T>
class BSTNode
{
public:
	BSTNode(T& val, BSTNode* left, BSTNode* right);
	~BSTNode();
	T GetVal();
	BSTNode* GetLeft();
	BSTNode* GetRight();
	
private:
	T val;
	BSTNode* left;
	BSTNode* right;
	int depth, height;
	friend class BST<T>;
};


template <class T>
class BST
{
public:
	BST();
	~BST();

	void Clear(void);
	bool IsEmpty(void);


	bool Search(T& val);
	void Insert(T& val);

	bool DeleteNode(T& val);

	void PreorderDFT(void);
	void PreorderDFT(BSTNode<T>* node);
	void PostorderDFT(BSTNode<T>* node);
	void InorderDFT(BSTNode<T>* node);
	void Visit(BSTNode<T>* node);

	void BFT(void);

	void ComputeNodeDepths(void);
	void ComputeNodeHeights(void);
	BSTNode<T>* getRoot() const { return root; }

	int isSameStructure(BSTNode<T>* a, BSTNode<T>* b)
	{
		// 1. both empty  
		if (a == NULL && b == NULL)
			return 1;
		// 2. both non-empty -> compare them  
		if (a != NULL && b != NULL)
		{
			return
				(
					isSameStructure(a->left, b->left) &&
					isSameStructure(a->right, b->right)
					);
		}
		// 3. one empty, one not -> false  
		return 0;
	}

	vector<T> Fill(BSTNode<T>* tree, vector<T>& vec)
	{
		vec.push_back(tree->GetVal());
		if (tree->right)
		{
			Fill(tree->right, vec);
		}
		if (tree->left)
		{
			return Fill(tree->left, vec);
		}
		return vec;
	}

	bool isSubTree(BST<T>& Tree2)
	{
		vector<T> vec1, vec2;
		vec1 = Fill(root, vec1);
		vec2 = Fill(Tree2.getRoot(), vec2);
		for (int i = 0; i < vec1.size(); i++)
		{
			if (vec2[0] == vec1[i])
			{
				for (int j = 0; j < vec2.size(); j++)
				{
					if (vec2[j] != vec1[i + j])
					{
						return false;
					}
				}
				return true;
			}
		}
		return false;
	}

	bool SimilarNodes(BST<T>& tree2)
	{
		vector<T> vec1, vec2;
		vec1 = Fill(tree2.getRoot(), vec1);
		vec2 = Fill(root, vec2);
		if (vec1.size() != vec2.size())
		{
			return false;
		}
		for (int i = 0; i < vec1.size(); i++)
		{
			for (int j = 0; j < vec2.size(); j++)
			{
				if (vec1[i] == vec2[j])
				{
					vec1[i] = 0;
					vec2[j] = 0;
				}
			}
		}
		for (int i = 0; i < vec1.size(); i++)
		{
			if (vec1[i] != 0 || vec2[i] != 0)
			{
				return false;
			}
		}
		return true;
	}

	bool HasSimilarShape(BST<T>& Tree2)
	{
		if (isSameStructure(root, Tree2.getRoot()))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	BST<T> getTree(T& v)
	{
		vector<T> vec1, vec;
		vec1 = Fill(root, vec1);
		for (int i = 0; i < vec1.size(); i++)
		{
			if (vec1[i] > v)
			{
				vec.push_back(vec1[i]);
			}
		}
		BST<T> newTree;
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i] << ",";
		}
		return newTree;
	}


	int* Merge(BST& T1, BST& T2)
	{
		int i;
		vector<T> vec;
		Fill(T1.getRoot(), vec);
		Fill(T2.getRoot(), vec);
		sort(vec.begin(), vec.end());
		for ( i = 0; i < vec.size(); i++)
		{
			cout << vec[i] << ",";
		}
		return &i;
	}

private:
	BSTNode<T> *root;

	bool Search(T& val, BSTNode<T>* node);

	void DelSingle(BSTNode<T> * ptr, BSTNode<T> * prev);
	void DelDoubleByCopying(BSTNode<T>* node);
	
	void ComputeDepth(BSTNode<T>* node, BSTNode<T>* parent);
	void ComputeHeight(BSTNode<T>* node);
	
	void Clear(BSTNode<T>* node);
};


template <class T>
BSTNode<T>::BSTNode(T& val_,
					BSTNode* left_,
				    BSTNode* right_)
{
	val = val_;
	left = left_;
	right = right_;
	depth = height = -1; // not computed yet
}


template <class T>
BSTNode<T>::~BSTNode()
{
}

template <class T>
T BSTNode<T>::GetVal()
{
	return val;
}

template <class T>
BSTNode<T>* BSTNode<T>::GetLeft()
{
	return left;
}

template <class T>
BSTNode<T>* BSTNode<T>::GetRight()
{
	return right;
}


template <class T>
BST<T>::BST(void)
{
	root = NULL;
}

template <class T>
BST<T>::~BST()
{
	Clear();
}

template <class T>
bool BST<T>::IsEmpty(void)
{
	return root == NULL;
}

// Iterative implementation of Search
// Asymptotic Complexity:
//		Best case: O(1) - If the value is at the root.
//		Worst case: O(height), where the height is O(logn) in balanced trees
//					and can be as bad as O(n) in non-balanced trees.
template <class T>
bool BST<T>::Search(T& x)
{
	BSTNode<T>* node = root; //Always start the search from the root
	
	while(node != NULL) 
	{
        // If the value that we are looking for is equal to
        // the value of the current tree node, we are done 
		if(x == node->val) 
			return true;

        // If the value that we are looking for is smaller than the 
        // value of the current tree node, go left; else, go right
		if(x < node->val)
			node = node->left;
		else
			node = node->right;
	}
    // If the loop completes, node will ncessarily be NULL,
    // which means that val was not found in the tree
	return false; 
}

// Recursive implementation of Search
// In a recursive implementation of the Search function, 
// the public Search will call the private recursive 
// Search as follows:

// bool BST<T>::Search(T& x)
// {
//      return Search(x, root);
// }

// x is the value that we are looking for
// node is the root of the sub-tree that we are searching in.
// Initially node is the root of the entire tree.
// Then the recursion will be limiting the search to
// smaller and smaller sub-trees 

// The asymptotic complexity of the recursive and the iterative search functions
// are the same. In some cases, a recursive function is more readable and easier to
// implement than its iterative equivailent. However, recursion requires more
// time to execute than loops due to the high cost of function calls.
template <class T>
bool BST<T>::Search(T& x, BSTNode<T>* node)
{
    // If recursion reaches a NULL node, x does not exist in the tree
	if(node == NULL)
		return false;

    // If recursion reaches a sub-tree whose root is equal to x, 
    // we are done 
	if(x == node->val)
		return true;

    // If the root of the current sub-tree is not the value that we
    // are looking for, do the search in either the left sub-tree
    // or the right sub-tree, depending on the value of x  
	if(x < node->val)
		return Search(x, node->left);
	else
		return Search(x, node->right);
}

template <class T>
void BST<T>::Insert(T& x)
{
    // Search for the right place for x starts from the root.
    // We also need to store the previous node as we move down
    // the tree, because the search will stop at a NULL pointer
    // and the previous of that NULL will be the parent of the
    // inserted node 
	BSTNode<T> *node = root, *prev = NULL;
   
    // Create a new node with NULL children, because we always 
    // insert a LEAF node. There is no insertion in the middle
    // of the tree
	BSTNode<T> *newNode = new BSTNode<T>(x, NULL, NULL);
	
    // Loop to search for the right position for x
	while(node != NULL)
	{
		prev = node;
		if(x < node->val)
			node = node->left;
		else
			node = node->right;
	}
    // When the loop terminates, node will always be NULL, which is
    // the NULL node to be replaced with the new node.
    // prev will be the parent of that NULL and therefore the parent
    // of the inserted new node      

    // Special handling of an empty tree is needed, because the 
    // inserted new node will have no parent in which a left/right 
    // pointer will need to be changed 
	if(IsEmpty() == true)
		root = newNode;

    // If the inserted new node is smaller than its parent, set the
    // the left pointer in the parent to the new node. Otherwise,
    // set the right pointer in the parent to the new node. 
	else if(x < prev->val)
		prev->left = newNode;
	else
		prev->right = newNode;
}

// Breadth-first traversal uses a queue
template <class T>
void BST<T>::BFT(void)
{
    // Create a queue to control the BFT.
    // Pay attention to the types used here.
    // The elements in the queue are pointers to BSTNode objects.
    // Storing BSTNode objects in the queue won't be space efficient,
    // because those objects may have large sizes.  
	QueueDLL<BSTNode<T>*> queue;
	BSTNode<T>* node = root;
	
    // If the tree is empty, there will be no nodes to traverse.
	if(node == NULL) return;
	
    // Initially, put the root in the queue
	queue.Enqueue(node);

	while(queue.IsEmpty() == false)
	{
        // Take a node out of the queue, process it and then insert 
        // its children into the queue.
		node = queue.Dequeue();
		Visit(node);
		if(node->left != NULL)
			queue.Enqueue(node->left);
		if(node->right != NULL)
			queue.Enqueue(node->right);
	}
}


// Non-recursive implementation of PreorderDFT
// Depth-first traversal uses a stack
template <class T>
void BST<T>::PreorderDFT()
{
    // Create a stack to control the DFT.
    // Pay attention to the types used here.
    // The elements in the stack are pointers to BSTNode objects.
    // Storing BSTNode objects in the stack won't be space efficient,
    // because those objects may have large sizes.  
	QueueDLL<BSTNode<T>*> queue;
	StackDLL<BSTNode<T>*> stack;
	BSTNode<T>* node = root;
	
    // If the tree is empty, there will be no nodes to traverse.
	if(node == NULL) return;
	
    // Initially, put the root in the stack
	stack.push(node);

	while(stack.isEmpty() == false)
	{
        // Take a node out of the stack, process it and then insert 
        // its children into the stack.
        // Because elements that are pushed last will be popped 
        // first, and we want to visit the left children before 
        // the right children, we will have to push the right child
        // before the left child for each node. 
		node = stack.pop();
		Visit(node);
		if(node->right != NULL)
			stack.push(node->right);
		if(node->left != NULL)
			stack.push(node->left);
	}
}

// Recursive implementation of PreorderDFT
// Recursive DFT implicitly uses the system's run-time stack
template <class T>
void BST<T>::PreorderDFT(BSTNode<T>* node)
{
	if(node == NULL) return;
	Visit(node); // Process the node before all of its children 
	PreorderDFT(node->left);
	PreorderDFT(node->right);
}

// Recursive implementation of PostorderDFT
// Recursive DFT implicitly uses the system's run-time stack
template <class T>
void BST<T>::PostorderDFT(BSTNode<T>* node)
{
	if(node == NULL) return;
	PostorderDFT(node->left);
	PostorderDFT(node->right);
	Visit(node); // Process the node after all of its children
}

// Recursive implementation of InorderDFT
// Recursive DFT implicitly uses the system's run-time stack
template <class T>
void BST<T>::InorderDFT(BSTNode<T>* node)
{
	if(node == NULL) return;
	InorderDFT(node->left);

	// Process the node after processing its left subtree 
	// but before processing its right subtree 
	Visit(node);  
	
	InorderDFT(node->right);
}

// The processing done at each node is simply printing its value 
template <class T>
void BST<T>::Visit(BSTNode<T>* node)
{
	cout << node->val << ", ";
}



// Deletes from the tree the node with the given value.
// Asymptotic complexity:
//		The delete function includes two steps: a search step + a delete step.
//		
//		- The search step is O(height) in the worst case and O(1) in the best 
//		case as explained in the search function.
//
//		- The delete step may be O(1) or O(height) depending on whether there
//	    is a search for a replacement or not and where the replacement is found.
//      Search for a replacement is done only if the deleted node has two children.
//      Note that the search for a replacement happens after the search for the
//      deleted node itself.
//		
//		Examples: 
//			- If the node to be deleted is at the root and has two children, the
//			search for the deleted node itself will be O(1) but the delete 
//          operation (search for a replacement then copy) will be O(height).
//
//			- If the node to be deleted is a leaf node, then the search for the
//          deleted node will be O(height) and the delete will be O(1) 
//          (no replacement is needed at all).
//
//			- If the node to be deleted is the root node and has a single
//			child, the search for the deleted node will be O(1) and the 
//          delete will be O(1) as well, because there will be no search for
//          a replacement.
//
//		Therefore, the delete function is O(height) in the worst case and O(1) 
//      in the best case.
template <class T>
bool BST<T>::DeleteNode(T& val)
{
	BSTNode<T> * node = root;
	BSTNode<T> * prev = NULL;
	
	if (IsEmpty() == true)
		return false;

	// This loop searches for the node to be deleted 
	while (node != NULL)
	{
		if (node->val == val)
			break;
		
		prev = node;
		if (val < node->val)
			node = node->left;
		else
			node = node->right;
	}
	
	// If node is not found, return false without deleting anything
	if (node == NULL)
		return false;
	
	// If the node has a single child, call DelSingle; else, call DelDouble
	if (node->left == NULL || node->right == NULL)
		DelSingle(node, prev);
	else
		DelDoubleByCopying(node);
	
	return true;
}


// Deletes a node with at most one child.
// This function is O(1) in the best and worst case.
template <class T>
void BST<T>::DelSingle(BSTNode<T>* ptr, BSTNode<T> * prev)
{
    // Special handling if the node to be deleted is the root
	if (ptr == root) {
		// The new root becomes child that is not NULL
		if (root->left != NULL)
			root = root->left;
		else
			root = root->right;
	// If the node to be deleted is the left child of its parent,
	// set the parent's left child to the only child of the deleted node
	} else if (ptr == prev->left) {
		if (ptr->right != NULL)
			prev->left = ptr->right;
		else
			prev->left = ptr->left;
	// If the node to be deleted is the right child of its parent,
	// set the parent's right child to the only child of the deleted node
	} else {
		if (ptr->right != NULL)
			prev->right = ptr->right;
		else
			prev->right = ptr->left;
	}
	
	delete ptr;
}

// Deletes a node with exactly two children.
// This function is O(height) in the worst case and O(1) in the best case.
template <class T>
void BST<T>::DelDoubleByCopying(BSTNode<T>* node)
{
	// The replacement will be the largest node in the left subtree.
	// So, start searching for a replacement by going left
	BSTNode<T> * rep = node->left; 
	BSTNode<T> * prev = node;
	
	// Then keep going right until you reach a node with no right,
	// as the largest node in the left subtree is the rightmost 
	// node in the left subtree.
	while (rep->right != NULL) {
		prev = rep;
		rep = rep->right;
	}
	
	// Copy the value of the replacement into the node to be deleted 
	node->val = rep->val;

	// Then delete the replacement node using DelSingle, because that
	// node does not have a right child.
	DelSingle(rep, prev);
}

template <class T>
void BST<T>::ComputeNodeDepths(void)
{
	ComputeDepth(root, NULL);
}


// Computes the depths for all of the nodes in the tree.
// Pre-order traversal, because the parent's depth has to be
// computed before computing the children's depths.
template <class T>
void BST<T>::ComputeDepth(BSTNode<T>* node, BSTNode<T>* parent)
{
	if(node == NULL) return;

	// The base of the computation is setting the root's depth to 0 
	if(node == root)
		node->depth = 0;
	else // For all other nodes, the depth is one plus the parent's depth
		node->depth = parent->depth + 1;
	ComputeDepth(node->left, node);
	ComputeDepth(node->right, node);
}


template <class T>
void BST<T>::ComputeNodeHeights(void)
{
	ComputeHeight(root);
}

// Computes the heights for all of the nodes in the tree.
// Post-order traversal, because children's heights have
// to be computed before computing the parent's height
template <class T>
void BST<T>::ComputeHeight(BSTNode<T>* node)
{
	if(node == NULL) return;

	// By setting these variables to -1, the height computation formula (last 
	// line in this function) will compute a zero height for a leaf node, because
	// the leaf node does not have any children. This will be the base of the computation
	int leftHeight = -1, rightHeight = -1;
	
	// Recursively compute the heights of all children
	// in the left and right sub-trees
	ComputeHeight(node->left);
	ComputeHeight(node->right);
	
	if(node->left)
		leftHeight = node->left->height;
	if(node->right)
		rightHeight = node->right->height;

	// The height of a node is one plus the height of the deepest subtree below it
	node->height = MAX(leftHeight, rightHeight) + 1;
}

template <class T>
void BST<T>::Clear(void)
{
	Clear(root);
	root = NULL;
}

// Deleting nodes is best done in postorder, because we cannot
// delete a node until we have taken its left and its right.  
template <class T>
void BST<T>::Clear(BSTNode<T>* node)
{
	if(node == NULL) return;
	Clear(node->left);
	Clear(node->right);
	delete node;
}

int MAX(int x, int y)
{
	return x>y ? x: y;
}