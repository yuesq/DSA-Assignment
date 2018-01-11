// DSA Assignment.cpp : Defines the entry point for the console application.


#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

#include "BST.h"
BST bst;
ItemType value;

void displayMenu();
void opt1();
void opt2();
void opt3();
void opt4();
void opt5();
void opt6();

int main()
{
	int n;
	cout << "Enter integer to initialise tree: " << endl;
	cin >> n;
	void displayMenu();

	system("PAUSE");
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
	cout << "Enter option: " << endl;
}

void opt1()	//search for a value
{
	cout << "Enter a value to search: " << endl;
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
	cout << "Enter value to add: " << endl;
	cin >> v;
	bst.insert(v);
}

void opt3() //remove a value
{
	int v;
	cout << "Enter value to delete: " << endl;
	cin >> v;
	bst.remove(v);
}

void opt4() //display values in ascending order 
{

}

void opt5() //display value in node k 
{

}

void opt6() //display the tree
{

}



