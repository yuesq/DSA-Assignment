// DSA Assignment.cpp : Defines the entry point for the console application.

//Jessica Das Roy 
//S10171178
//ISF02
//PO2

//Yue Shiqi
//S10171209
//ISF02
//PO2


#pragma once
#include "stdafx.h"
#include <iostream>
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
void opt8();
void opt9();

int main()
{
	opt9();

	int opt = -1;

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
		else if (opt ==5)
		{
			opt5();
		}
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

		else if (opt == 8)
		{
			opt8();
		}

		else if (opt == 9)
		{
			opt9();
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
	cout << "[8] Destroy the tree" << endl;
	cout << "[9] Create a new Tree" << endl;
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
	BinaryNode* test;
	test = bst.search2(v);
	
	if (test != NULL)
	{
		bst.remove(v);
		cout << value << " has been removed from the tree.";
	}

	else
	{
		cout << "Sorry, the item does not exist in the tree." << endl;
	}

}

void opt4() //display values in ascending order 
{
	bst.inorder();
}

//kth node
void opt5() //display value in node k
{
	int k = 1;
	int count;
	count = bst.countNodes();
	bool empty = bst.isEmpty();
	bool success = (k > 0 && k <= count);
	
	if (empty)
	{
		cout << "There are no items in the tree." << endl;
	}
	
	else
	{
		cout << "There are " << count << " nodes in the tree." << endl;
		cout << "Enter any number between 1 and " << count << " to display the value within the node: ";
		cin >> k;
		bst.levelOrder(k);
	}

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

void opt8()
{
	bst.deconstructor();
}

void opt9()
{
	bool test = bst.isEmpty();
	if (test)
	{
		int m = 0;
		int s;

		while (m == 0)
		{
			cout << "Enter integer to initialise tree: ";
			cin >> s;
			bool success = (s > 0) && (s % 1 == 0);

			if (success)
			{
				m = 1; // breaks out of loop
				bst.initialise(s);
				cout << "Your tree has been created." << endl;
				break;
			}

			else if (!success)
			{

				cout << "You have entered an invalid input. Try again." << endl;
				cin.clear();
				cin.ignore();
				cin.fail();
			}
		}
	}

	else
	{
		cout << "Sorry, you already have a tree. Destroy the tree before creating a new one. " << endl;
	}
}