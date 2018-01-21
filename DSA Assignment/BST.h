#pragma once
// BST.h

#include "BinaryNode.h"
<<<<<<< HEAD
#include <unordered_map>
#include <algorithm>
#include <type_traits>
//#include "Queue.h"
=======
>>>>>>> parent of c0e4265... remove was fixed

class BST
{
private:

	BinaryNode* root;		// root of the BST

public:

	// constructor
	BST();

	// deconstructor
	void deconstructor();
	void deconstructor(BinaryNode* &root);

	// search an item in the binary search tree
	BinaryNode* search(ItemType value);
	BinaryNode* search(BinaryNode* root, ItemType value);

	// initialise a data array
	void initialise(ItemType value);

	// convert array into binary search tree
	BinaryNode* convert(int(arr[]), int start, int end, BinaryNode* &root);
	// convert binary search tree into array
	int addToArray(BinaryNode* t, int arr[], ItemType item);

	// insert an item to the binary search tree
	void insert(ItemType item);
	void insert(BinaryNode* &root, ItemType item);

	// create AVL tree from binary search tree
	// rotations
	BinaryNode *rr_rotation(BinaryNode *t);
	BinaryNode *ll_rotation(BinaryNode *t);
	BinaryNode *lr_rotation(BinaryNode *t);
	BinaryNode *rl_rotation(BinaryNode *t);

	//balance the tree
	BinaryNode* rebalance();
	BinaryNode* rebalance(BinaryNode *t);

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
	void nodeK(int n);


	// display the tree
	void display();
	void display(BinaryNode *ptr, int level);
<<<<<<< HEAD

	/*
	void printLevel(Queue &q);
	void printLevel(BinaryNode* t, Queue &q);
	void BST::printGivenLevel(BinaryNode* t, int level, Queue &q);
	void BST::printLevelOrder(int depth);
	void BST::printLevelOrder(BinaryNode* t, int depth);
	*/
=======
>>>>>>> parent of c0e4265... remove was fixed
	
};
