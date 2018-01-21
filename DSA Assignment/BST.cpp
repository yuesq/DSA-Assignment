// BST.cpp
#pragma once
#include "stdafx.h"
#include<iostream>
//#include <sstream>
#include <string>
#include <cmath>
#include <cstddef>  // for NULL
#include <new>      // for bad_alloc
#include <algorithm>
#include <vector>
#include "BST.h"
//#include "Queue.h"


using namespace std;

#define max(x,y) ((x > y) ? x : y)
#define min(x,y) ((x < y) ? x : y)

// constructor
BST::BST()
{
	root = NULL;
}

// deconstructor
void BST::deconstructor()
{
	if (!isEmpty())
	{
		cout << "Tree has been destroyed. " << endl;
		deconstructor(root);
	}

	else
	{
		cout << "There is no tree to destroy." << endl;
	}
}

void BST::deconstructor(BinaryNode* &root)
{
	if (root != NULL)
	{
		BinaryNode *del;
		deconstructor(root->left);
		deconstructor(root->right);
		del = root;
		free(del);
		root = NULL;
	}
}

// initialise values and insert into tree
void BST::initialise(ItemType value)
{
	//m is the sum of all node values in the bst
	int m = 0;

	for (int i = 1; m <= value; i++)
	{
		//calculate values
		// insert values into tree
		cout << "value in tree = " << i << endl;
		insert(i);
		m += i;
	}
	cout << "sum is = " << m << endl;

}

// convert array into binary search tree
BinaryNode* BST::convert(int (arr[]), int start, int end, BinaryNode* &root)
{
	//create int for mid of array
	//end = end + (((end-start)%2)?1:0);
	int mid = (start + end) / 2;

	insert(mid);

	for (int i = 1; i<=(end-1); i++)
	{
		if (i == mid)
			continue;
		else
			insert(arr[i-1]);
	};
	return root;
}

// convert binary search tree into array
int BST::addToArray(BinaryNode* t, int arr[], ItemType size)
{

	if (t == NULL)
		return 0;

	else
	{
		arr[size] = t->item;

		if (t->left != NULL)
		{
			addToArray(t->left, arr, size);
		}

		if (t->right != NULL)
		{
			addToArray(t->right, arr, size);
		}

		arr[size] = t->item;
		size++;
	}

	return(t->item);
}


// search an item in the binary search tree
BinaryNode* BST::search(ItemType value)
{
	//check if tree is not empty
	if (root != 0)
	{
		//prints the root of the tree
		cout << "found root = " << root->item << endl;
		
		//prints path to item
		return search(root, value);
	}
	
	// tree is empty
	else
	{
		cout << "There is no tree." << endl;
		return NULL;
	}
}

BinaryNode* BST::search(BinaryNode* root, ItemType value)
{
	if (root == NULL)	// item not found
	{
		cout << "The item was not found" << endl;
		return NULL;
	}
	else if (root->item == value) //item found
	{
		cout << "The item was found." << endl;
		return root;
	}

	//1. if value>item but not in tree
	//   it will print the path it took to find the value 
	//2. then print L/R (based on which side of the node is empty)
	//3. then print "not found"

	//1. if value> last item of subtree
	//   it will print all the Rs and Ls needed 
	//2. then print another L/R
	//3. then print "not found"
	else
	{
		if (value < root->item)// search in left subtree
		{
			cout << "L" << endl;
			return search(root->left, value);
		}
		else // search in right subtree
		{
			cout << "R" << endl;
			return search(root->right, value);
		}
	}
	
}

// insert an item to the binary search tree
void BST::insert(ItemType item)
{
	insert(root, item);
}

void BST::insert(BinaryNode* &t, ItemType item)
{
		if (t == NULL)
		{
			BinaryNode *newNode = new BinaryNode;
			newNode->item = item;
			newNode->left = NULL;
			newNode->right = NULL;
			t = newNode;
			cout << item << " has been added to the tree." << endl;
		}
		else if (item < t->item)
		{
			insert(t->left, item);  // insert in left subtree
			t = rebalance(t);
		}
		else if (item > t->item)
		{
			insert(t->right, item); // insert in right subtree
			t = rebalance(t);
		}
		else
		{
			cout << "Item already exists in tree. Item cannot be added to the tree." << endl;
			return;
		}
}

//Balance BST tree to make it AVL
BinaryNode* BST::rebalance()
{
	return(rebalance(root));
}
//Balance BST tree to make it AVL
BinaryNode* BST::rebalance(BinaryNode *t)
{
	//store intial height diff into a var called balFactor. 
	//balFactor == balance factor
	//balance factor is the height difference between the sub trees
	//left subtree - right subtree = 0		: no difference in heights
	//left subtree - right subtree = -1		: right is heavier by one level. but is balanced
	//left subtree - right subtree = 1		: left subtree is heavier by one level, but is balanced
	// if numbers are less than -1 or more than 1, the difference in height is 2
	//means tree is unbalanced and needs to be balanced
	int balFactor = heightDiff(t);

	// check if tree is already balanced
	if (isBalanced())
	{
		return t;
	}

	// tree is unbalanced, perform rebalance
	else
	{
		//if left is heavier
		if (balFactor > 1)
		{
			//compare height diff of left child node with parent node
			if (heightDiff(t->left) > 0)
				t = ll_rotation(t);

			//compare height diff of right child with parent node
			else
				t = rr_rotation(t);
		}

		//if right is heavier
		else if (balFactor < -1)
		{
			if (heightDiff(t->right) > 0)
				t = rl_rotation(t);
			else
				t = rr_rotation(t);
		}
		return t;
	}
	
}

//AVL rotations
// right right rotation
BinaryNode *BST::rr_rotation(BinaryNode *root)
{
	//create temporary node
	BinaryNode *t;
	//assign value of right subtree into temp ptr
	t = root->right;
	//right child of root = left child of temp
	root->right = t->left;
	t->left = root;
	return t;
}

//left left rotation
BinaryNode *BST::ll_rotation(BinaryNode *root)
{
	//create temporary node
	BinaryNode *t;
	//assign value of left subtree into temp ptr
	t = root->left;
	//left child of root = right child of temps
	root->left = t->right;
	t->right = root;
	return t;
}

//left right rotation
BinaryNode *BST::lr_rotation(BinaryNode *root)
{
	BinaryNode *t;
	t = root->left;
	root->left = rr_rotation(t);
	return ll_rotation(root);
}

//right left rotation
BinaryNode *BST::rl_rotation(BinaryNode *parent)
{
	BinaryNode *t;
	t = root->right;
	root->right = ll_rotation(t);
	return rr_rotation(root);
}

// delete an item from the binary search tree
void BST::remove(ItemType value)
{
	if (isEmpty())
	{
		cout << "There is no tree. No values can be removed." << endl;
	}
	else
		remove(root, value);
}

void BST::remove(BinaryNode* &t, ItemType value)
{
	// search for the node to be deleted

	BinaryNode* current = t;
	BinaryNode* parent = NULL;
	bool isLeftChild = false;
	bool found = false;
	while ((!found) && (current != NULL))
	{
		if (value == current->item)
		{
			found = true;
		}
		else
		{
			parent = current;
			if (value < current->item)
			{
				current = current->left;	// go to left subtree
				isLeftChild = true;
			}
			else
			{
				current = current->right;	// go to right subtree
				isLeftChild = false;
			}
		}
	}

	if (found)
	{
		root = rebalance();
		// -----------------------  case 1 : node is a leaf ------------------------
		if (current->left == NULL && current->right == NULL)
		{
			if (current == t)	// node to be deleted is a root
			{
				t = NULL;
			}
			else
			{
				if (isLeftChild)
				{
					parent->left = NULL;
				}
				else
				{
					parent->right = NULL;
				}

			}

		}
		else
			// -----------------------  case 2 : node has only 1 child  ----------------
		{

			if (current->left == NULL)
			{
				if (current == t)
				{
					t = current->right;
				}

				else if (isLeftChild)
				{
					parent->left = current->right;
				}
				else
				{
					parent->right = current->right;
				}


			}

			else if (current->right == NULL)
			{
				if (current == t)
				{
					t = current->left;
				}
				else if (isLeftChild)
					parent->left = current->left;
				else
					parent->right = current->left;

			}
			else
				// -----------------------  case 3 : node has 2 children  ------------------
			{
				// find the successor ( rightmost child in the node’s left subtree)
				BinaryNode* successor = current->left;
				while (successor->right != NULL)
					successor = successor->right;
				// replace the node’s item with that of the successor
				int n = successor->item;
				// delete the successor (either case 1 or case 2)
				remove(t, n);
				// replace the node’s item with that of the successor
				current->item = n;
			}
		}
		cout << value << " has been removed from the tree." << endl;
	}

	else
	{
		cout << "Sorry, the item does not exist in the tree." << endl;
	}
	
}

// traverse the binary search tree in inorder
void BST::inorder()
{
	if (isEmpty())
		cout << "Sorry! No items were found." << endl;
	else
		inorder(root);
}

void BST::inorder(BinaryNode* t)
{
	if (t != NULL)
	{
		inorder(t->left);
		cout << t->item << endl;
		inorder(t->right);
	}
	else
		return;					//NEW LINE
}
// traverse the binary search tree in preorder
void BST::preorder()
{
	if (isEmpty())
		cout << "Sorry! No items were found." << endl;
	else
		preorder(root);
}

void BST::preorder(BinaryNode* t)
{
	if (t != NULL)
	{
		cout << t->item << endl;
		preorder(t->left);
		preorder(t->right);
	}
}

// traverse the binary search tree in postorder
void BST::postorder()
{
	if (isEmpty())
		cout << "Sorry! No items were found." << endl;
	else
		postorder(root);
}

void BST::postorder(BinaryNode* t)
{
	if (t != NULL)
	{
		postorder(t->left);
		postorder(t->right);
		cout << t->item << endl;
	}
}

// compute the height of the binary search tree
int BST::getHeight()
{
	return getHeight(root);
}

int BST::getHeight(BinaryNode* t)
{
	int treeHeight = 0;;

	if (t == NULL)
		return 0;
	else
	{
		//initialise left height as a value in pointer var
		int leftHeight = getHeight(t->left);
		//initialise right height as a value in another pointer var
		int rightHeight = getHeight(t->right); 
		//compare the two to see which side of the tree is taller
		int maxHeight = max(leftHeight, rightHeight);
		treeHeight = maxHeight + 1;

		return (treeHeight);
	}
}

//compute the height difference between the left and right subtree
int BST::heightDiff()
{
	//if tree is empty
	//return height = 0
	if (isEmpty())
	{
		return 0;
	}

	//tree is not empty
	//return the height difference between the subtrees
	else
		return heightDiff(root);
}

int BST::heightDiff(BinaryNode* t)
{
	
	int leftHeight = 0;
	int rightHeight = 0;
	
	//get heights of each side of tree
	//store heights into variables

	leftHeight = getHeight(t->left);
	rightHeight = getHeight(t->right);

	//return the difference between the heights
	return (getHeight(t->left) - getHeight(t->right));
}

// count the number of nodes in the binary search tree
int BST::countNodes()
{
	return countNodes(root);
}

int BST::countNodes(BinaryNode* t)
{
	if (t == NULL)
		return 0;
	else
		return 1 + countNodes(t->left) + countNodes(t->right);
}

// check if the binary search tree is balanced
bool BST::isBalanced()
{
	return isBalanced(root);
}

bool BST::isBalanced(BinaryNode* t)
{
	if (t != NULL)
	{
		int leftHeight = getHeight(t->left);
		int rightHeight = getHeight(t->right);
		bool balanced = (abs(leftHeight - rightHeight) <= 1);
		return (balanced && isBalanced(t->left) && isBalanced(t->right));
	}
	else
		return true;
}

// check if the binary search tree is empty
bool BST::isEmpty()
{
	return (root == NULL);
}

void BST::nodeK(int k)
{
	//dynamic queue 
	vector<BinaryNode*> vec; 

	if (isEmpty())
	{
		cout << "There is no tree." << endl;
		return;
	}

	vec.push_back(root);
	int front = 0;
	while (front < vec.size())
	{
		// base case
		// node k was found
		if (front == (k -1))
		{
			cout << "The value of node " << k << " is " << vec[front]->item << endl;
			return;
		}

		else
		{
			if (vec[front]->left != NULL)
			{
				vec.push_back(vec[front]->left);
			}
			if (vec[front]->right != NULL)
			{
				vec.push_back(vec[front]->right);
			}

		}
		front += 1;
	}
}

//display tree
void BST::display()
{
	int level = getHeight();
	if (level == 0)
	{
		cout << "There is no tree to be displayed. " << endl;
	}
	else
		display(root, 1);
}

void BST::display(BinaryNode *ptr, int level)
{
	int i;
	if (ptr != NULL)
	{
		display(ptr->right, level + 1);
		cout << endl;
		if (ptr == root)
			cout << "root->";
		else
		{
			for (i = 0; i < level && ptr != root; i++)
				cout << "     ";
		}
		cout << ptr->item;
		display(ptr->left, level + 1);
	}
}

/*
void BST::printLevel(Queue &q)
{
	return printLevel(root, q);
}

void BST::printLevel(BinaryNode *t, Queue &q) {
	int h = getHeight(t);
	for (int i = 1; i <= h; i++)
		printGivenLevel(t, i, q);
}

string printTree(BinaryNode *root, int level, string gap) {
	if (level == 1) {
		if (root == 0) {
			return gap + "-" + gap;
		}
		stringstream out;
		out << root->item;
		return gap + out.str() + gap;
	}
	else if (level>1) {
		string leftStr = printTree(root ? root->left : 0, level - 1, gap);
		string rightStr = printTree(root ? root->right : 0, level - 1, gap);

		return leftStr + " " + rightStr;
	}
	else return "";
}

void BST::printGivenLevel(BinaryNode* t, int level, Queue &q)
{
	if (t == NULL)
		return;
	if (level == 1)
	{
		q.enqueue(t->item);
	}
	else if (level > 1)
	{
		printGivenLevel(t->left, level - 1, q);
		printGivenLevel(t->right, level - 1, q);
	}
}
void BST::printLevelOrder(int depth) {
	printLevelOrder(root, depth);
}

void BST::printLevelOrder(BinaryNode* root, int depth) {
	for (int i = 1; i <= depth; i++) {
		string gap = "";
		for (int j = 0; j<pow(2, depth - i) - 1; j++) {
			gap += " ";
		}
		string levelNodes = printTree(root, i, gap);
		cout << levelNodes << endl;
	}
}
*/
