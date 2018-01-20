//Jessica Das Roy 
//S10171178
//ISF02
//PO2

//Yue Shiqi
//S10171209
//ISF02
//PO2

// DSA Assignment.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <string>
#include "BST.h"
using namespace std;

BST bst;
ItemType value;

int main();

void displayMenu();
void opt1();
void opt2();
void opt3();
void opt4();
void opt5();
void opt6();
void opt7();

int main()
{
	// s is an integer given by the user
	int s;
	cout << "Enter integer to initialise tree: ";
	cin >> s;

	// success when the input is an integer greater than 0
	bool success = ((s % 1 == 0) && (s > 0));

	while (int k = 1)
	{
		if (success)
		{
			k = 0;
			break;
		}

		else
		{
			cin.clear();
			cin.ignore();
			cout << "Input must be valid. Please enter a valid number: ";
			cin >> s;
		}
	}

	//create binary search tree
	bst.initialise(s);
	int opt= -1;

	while (opt != 0)
	{
		displayMenu();
		cout << "Enter option: ";
		cin >> opt;

		if (opt == 1)
		{
			opt1();
		}

		else if (opt == 2)
		{
			opt2();
		}

		else if (opt == 3)
		{
			opt3();
		}

		else if (opt == 4)
		{
			opt4();
		}
		//*
		else if (opt ==5)
		{
			opt5();
		}
		//*/
		else if (opt == 6)
		{
			opt6();
		}
		
		else if (opt == 0)
		{
			cout << "Thank you!" << endl;
			break;
		}

		else if (opt == 7)
		{
			opt7();
		}

		else
		{
			cout << "Sorry, you have entered an invalid option. Please try again." << endl;
		}
			
			
	}

	system ("PAUSE");
    return 0;
}

void displayMenu()
{
	cout << endl;
	cout << "===== Binary Search Tree Application =====" << endl;
	cout << "[1] Search for a value" << endl;
	cout << "[2] Add a value" << endl;
	cout << "[3] Remove a value" << endl;
	cout << "[4] Display values in ascending order" << endl;
	cout << "[5] Display value of node K" << endl;
	cout << "[6] Check if tree is balanced" << endl;
	cout << "[7] Display the tree" << endl;
	cout << "[0] Exit" << endl;
	cout << "============================================" << endl;
}

void opt1()	//search for a value
{
	cout << "Enter a value to search: ";
	cin >> value;
	bst.search(value);

}

void opt2() //add a value
{
	int v;
	cout << "Enter value to add: ";
	cin >> v;
	bst.insert(v);
}

void opt3() //remove a value
{
	int v;
	cout << "Enter value to delete: ";
	cin >> v;
	bst.remove(v);
}

void opt4() //display values in ascending order 
{
	bst.inorder();
}

void opt5() //display value in node k 
{
	// store the total number of nodes in var
	int count;
	count = bst.countNodes();

	// intialise int value of k
	// k is the kth node that the user wants to find
	int k;

	// initialise int var
	// "final" is the value that is returned by the function
	int final;

	// check if tree is empty
	// int test = nodeK(k);

	cout << "There are " << count << " nodes in this tree." << endl;
	cout << "Which node would you like to find? " << endl;
	cin >> k;
	final = bst.nodeK(k);
	cout << "This is the value of the node you wanted to find: " << final << endl;
}


void opt6()	//check if tree is balanced
{
	bool test = bst.isBalanced();
	if (test == true)
	{
		cout << "Tree is balanced." << endl;
	}

	else
		cout << "Tree is unbalanced." << endl;
}

void opt7() //display the tree
{
	bst.display();
}
