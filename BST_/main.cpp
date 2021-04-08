#include"BST_withComments.h"
#include<iostream>

using namespace std;

int main()
{
	int a[] = { 4,2,3,1,7,20,5 };
	int b[]= { 4,2,3,1,7,5,20 };
	int c[] = { 1,45,42,34 };
	int d[] = { 54,52,53,51,57,70,55 };
	int e[] = { 4,2,3,5 };
	int limit = 54;
	BST<int> tree1, tree2, tree3, tree4,tree5;
	for (int i = 0; i < 7; i++)
	{
		tree1.Insert(a[i]);
		tree2.Insert(b[i]);
		if (i < 4)
		{
			tree3.Insert(c[i]);
			tree5.Insert(e[i]);
		}
		tree4.Insert(d[i]);
	}
	cout << "Values in tree 1 are: ";
	tree1.InorderDFT(tree1.getRoot());
	cout << "\nValues in tree 2 are: ";
	tree2.InorderDFT(tree2.getRoot());
	cout << "\nValues in tree 3 are: ";
	tree3.InorderDFT(tree3.getRoot());
	cout << "\nValues in tree 4 are: ";
	tree4.InorderDFT(tree4.getRoot());
	cout << "\nValues in tree 5 are: ";
	tree5.InorderDFT(tree5.getRoot());

	cout << "\n\nTest if tree 1 and tree 2 have similar nodes 1=YES, 0=NO\nAns: " << tree1.SimilarNodes(tree2);
	cout << "\nTest if tree 1 and tree 3 have similar nodes 1=YES, 0=NO\nAns: " << tree1.SimilarNodes(tree3);
	cout << "\nTest if tree 1 and tree 4 have similar nodes 1=YES, 0=NO\nAns: " << tree1.SimilarNodes(tree4);

	cout << "\n\nTest if tree 1 and tree 2 have similar shape 1=YES, 0=NO\nAns: " << tree1.HasSimilarShape(tree2);
	cout << "\nTest if tree 1 and tree 3 have similar shape 1=YES, 0=NO\nAns: " << tree1.HasSimilarShape(tree3);
	cout << "\nTest if tree 1 and tree 4 have similar shape 1=YES, 0=NO\nAns: " << tree1.HasSimilarShape(tree4);

	cout << "\n\nTree after setting high value limit = 54\n";
	cout << "Values in tree 4 are: ";
	tree4.getTree(limit);

	cout << "\n\nSubtree test of tree1 and tree5 1=YES, 0=NO\nAns: " << tree1.isSubTree(tree5);
	cout << "\n\nSubtree test of tree1 and tree2 1=YES, 0=NO\nAns: " << tree1.isSubTree(tree2);

	cout << "\n\nMerge test of tree 1 and tree 3: ";
	tree1.Merge(tree1, tree3);
}