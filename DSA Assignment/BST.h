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

	// deconstructor
	void deconstructor(BinaryNode* &root);

	// search an item in the binary search tree
	BinaryNode* search(ItemType value);
	BinaryNode* search(BinaryNode* root, ItemType value);

	//initialise a data array
	void initialise(ItemType value);

	//convert array into binary search tree
	BinaryNode* convert(int(arr[]), int start, int end, BinaryNode* &root);

	// insert an item to the binary search tree
	BinaryNode* insert(ItemType item);
	BinaryNode* insert(BinaryNode* &root, ItemType item);

	// create AVL tree from binary search tree
	// rotations
	BinaryNode *rr_rotation(BinaryNode *);
	BinaryNode *ll_rotation(BinaryNode *);
	BinaryNode *lr_rotation(BinaryNode *);
	BinaryNode *rl_rotation(BinaryNode *);

	//balance the tree
	BinaryNode* rebalance();
	BinaryNode* rebalance(BinaryNode *);

	//insertion
	//BinaryNode* insert(BinaryNode *, int);

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

	//calculates height?
	void updateHeight();

	// compute the height of the binary search tree
	int getHeight();
	int getHeight(BinaryNode* t);

	//compute the height difference between the subtrees
	int heightDiff();
	int heightDiff(BinaryNode* t);

	// count the number of nodes in the binary search tree
	int countNodes();
	int countNodes(BinaryNode* t);

	// check if the binary search tree is empty
	bool isEmpty();

	// check if the binary search tree is balanced
	bool isBalanced();
	bool isBalanced(BinaryNode *t);

	// look for node K
	BinaryNode* nodeK(ItemType item);
	BinaryNode* nodeK(BinaryNode* root, ItemType item);

	// display the tree
	void display();
	void display(BinaryNode *ptr, int level);

	///
	
};
