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
using namespace std;

#include "BST.h"
BST bst;
ItemType value;

int main();

void displayMenu();
void opt1();
void opt2();
void opt3();


/*void opt4();
void opt5();
void opt6();*/

int main()
{
	//s is an integer given by the user
	int s;
	cout << "Enter integer to initialise tree: ";
	cin >> s;


	//validation if s not an integer
	while (cin.fail() || s<0)
	{
		cout << "Input must be valid. Please enter a valid number: ";
		cin.clear();
		cin.ignore();
		cin >> s;
		bst.initialise(s);
	}


	while (true)
	{
		displayMenu();

		int opt;
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

		else if (opt == 0)
		{
			cout << "Thank you!" << endl;
			break;
		}
		else
			cout << "Sorry, you have entered an invalid option" << endl;
			
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
	cout << "[6] Display the tree" << endl;
	cout << "[0] Exit" << endl;
	cout << "============================================" << endl;
}

void opt1()	//search for a value
{
	cout << "Enter a value to search: ";
	cin >> value;
	BinaryNode* p = bst.search(value);
	if (p != NULL)
		cout << "Found" << endl;
	else
		cout << "Not Found" << endl;
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

/*void opt4() //display values in ascending order 
{

}

void opt5() //display value in node k 
{

}

void opt6() //display the tree
{

}
*/


