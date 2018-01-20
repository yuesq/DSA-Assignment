// BST.cpp

#include "stdafx.h"
#include<iostream>
#include <string>
#include <cmath>
#include <cstddef>  // for NULL
#include <new>      // for bad_alloc
#include <algorithm>
#include "BST.h"

using namespace std;

#define max(x,y) ((x > y) ? x : y)
#define min(x,y) ((x < y) ? x : y)

//m is the sum of all node values in the bst
int m = 0;

//i is the iteration
int i;

//dataArray is an array of the values to be put in the BST
//max number of values in array = 10 000
int dataArray[10000] = {};

// constructor
BST::BST()
{
	root = NULL;
}

// deconstructor
void BST::deconstructor(BinaryNode* &t)
{
	if (t != NULL)
	{
		deconstructor(t->left);
		deconstructor(t->right);
		delete t;
	}
}

//initialise values and insert into tree
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

//convert array into binary search tree
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

// search an item in the binary search tree
BinaryNode* BST::search(ItemType value)
{
	//prints the root of the tree
	if (root != 0)
	{
		cout << "found root = " << root->item << endl;
		return search(root, value);
	}
	
	//
	else
		return NULL;
}

BinaryNode* BST::search(BinaryNode* root, ItemType value)
{
	if (root == NULL)	// item not found
	{
		cout << "Not found" << endl;
		return NULL;
	}
	else if (root->item == value) //item found
		return root;

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
		}
		else if (item < t->item)
		{
			insert(t->left, item);  // insert in left subtree
			root = rebalance(root);
		}
		else if (item > t->item)
		{
			insert(t->right, item); // insert in right subtree
			root = rebalance(root);
		}
		else
			cout << "Item already exists in tree." << endl;
	
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

	//if left is heavier
	if (balFactor > 1)
	{
		//compare height diff of left child node with parent node
		if (heightDiff(t->left) > 0)
			t = rr_rotation(t);

		//compare height diff of right child with parent node
		else
			t = lr_rotation(t);
	}

	//if right is heavier
	else if (balFactor < -1)
	{
		if (heightDiff(t->right) < 0)
			t = ll_rotation(t);
		else
			t = rl_rotation(t);
	}
	return root;
}


//AVL rotations
// right right rotation
BinaryNode *BST::rr_rotation(BinaryNode *root)
{
	BinaryNode *t;
	t = root->right;
	root->right = t->left;
	t->left = root;
	return t;
}

//left left rotation
BinaryNode *BST::ll_rotation(BinaryNode *root)
{
	BinaryNode *t;
	t = root->right;
	root->right = t->left;
	t->left = root;
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
		// -----------------------  case 1 : node is a leaf ------------------------
		if (current->left == NULL && current->right == NULL)
		{
			if (current == t)	// node to be deleted is a root
				t = NULL;
			else
				if (isLeftChild)
					parent->left = NULL;
				else
					parent->right = NULL;
		}
		else
			// -----------------------  case 2 : node has only 1 child  ----------------
			if (current->left == NULL)
			{
				if (current == t)
					t = current->right;
				else if (isLeftChild)
					parent->left = current->right;
				else
					parent->right = current->right;;
			}
			else
				if (current->right == NULL)
				{
					if (current == t)
						t = current->left;
					else if (isLeftChild)
						parent->left = current->left;
					else
						parent->right = current->left;;
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
}

// traverse the binary search tree in inorder
void BST::inorder()
{
	if (isEmpty())
		cout << "No item found" << endl;
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
		cout << "No item found" << endl;
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
		cout << "No item found" << endl;
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

//update height
//void BST::updateHeight()


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
		int leftHeight = getHeight(t->left);//initialise left height as a value in pointer var
		int rightHeight = getHeight(t->right); //initialise right height as a value in another pointer var
		int maxHeight = max(leftHeight, rightHeight); //compare the two to see which side of the tree is taller
		return (1+ maxHeight);
	}
}

//compute the height difference between the left and right subtree
int BST::heightDiff()
{
	//if tree is empty
	//return height = 0
	if (isEmpty())
	{
		cout << "Your tree is empty." << endl;
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

/*//look for node k
BinaryNode* BST::nodeK(ItemType value)
{
	if (isEmpty())
		return NULL;
	else
	{
		BinaryNode* newNode = new BinaryNode;
		newNode->item = value;
		BinaryNode *ptrNode = new BinaryNode;
		ptrNode = search(value);
		if (ptrNode == NULL)
		{
			cout << "Not found." << endl;
			return NULL;
		}

		else (ptrNode == root)
		{
			cout << "Found. " << endl;
			return root;
		}
	}
}

BinaryNode* BST::nodeK(BinaryNode* root, ItemType value)
{
	
}
*/

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



//MIGHT USE IN THE FUTURE
//IDK
/*
//insert function
BinaryNode* BST::insert(ItemType item)
{
return insert(root, item);
}

BinaryNode* BST::insert(BinaryNode* &root, ItemType item)
{
if (isEmpty())
{
root = new BinaryNode;
root->item = item;
root->left = NULL;
root->right = NULL;
return root;
}

//insert into left subtree
else if (item < (root->item))
{
insert((root->left), item);
root = balance(root);
}

//insert into right subtree
else if (item > (root->item))
{
insert((root->right), item);
root = balance(root);
}
return root;
}

//right rotation
BinaryNode* BST::r_rotation(BinaryNode* t)
{
BinaryNode *ptrNode;
ptrNode = t->left;
t->left = ptrNode->right;
ptrNode->right = t;

return ptrNode;
}

int BST::countNodes(BinaryNode* t)
{
if (t == NULL)
return 0;
else
return 1 + countNodes(t->left) + countNodes(t->right);
}

*/