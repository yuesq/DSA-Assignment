#pragma once
// BST.h

#include "BinaryNode.h"

class BST
{
private:

	BinaryNode* root;		// root of the BST

public:

	// constructor
	BST();

	// search an item in the binary search tree
	BinaryNode* search(ItemType value);
	BinaryNode* search(BinaryNode* root, ItemType value);

	//initialise a data array
	void initialise(ItemType value);

	//convert array into binary search tree
	BinaryNode* convert(int(arr[]), int start, int end, BinaryNode* &root);

	// insert an item to the binary search tree
	void insert(ItemType item);
	void insert(BinaryNode* &root, ItemType item);

	// delete an item from the binary search tree
	void remove(ItemType value);
	void remove(BinaryNode* &root, ItemType value);

	// traverse the binary search tree in inorder
	void inorder();
	void inorder(BinaryNode* t);

	// traverse the binary search tree in preorder
	void preorder();
	void preorder(BinaryNode* t);

	// traverse the binary search tree in postorder
	void postorder();
	void postorder(BinaryNode* t);

	// compute the height of the binary search tree
	int getHeight();
	int getHeight(BinaryNode* t);

	// count the number of nodes in the binary search tree
	int countNodes();
	int countNodes(BinaryNode* t);

	// check if the binary search tree is empty
	bool isEmpty();

	// check if the binary search tree is balanced
	bool isBalanced();
	bool isBalanced(BinaryNode *t);

};
