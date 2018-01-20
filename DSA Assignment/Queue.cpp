#include "stdafx.h"
#include <iostream>

// include necessary files
#include "BinaryNode.h"
#include "Queue.h"
#include "BST.h"

using namespace std;

//construct queue
Queue::Queue()
{
	frontNode = NULL;
	backNode = NULL;
}

// destroy queue
Queue::~Queue()
{
	while (!qIsEmpty())
		dequeue();
}

// check if queue is empty
bool Queue::qIsEmpty()
{
	return (frontNode == NULL);
}

// enqueue item in queue
bool Queue::enqueue(ItemType &item)
{
	Node *newNode = new Node;
	newNode->item = item;
	newNode->next = NULL;

	if (!qIsEmpty())
	{
		backNode->next = newNode;
		backNode = newNode;
	}
	else
	{
		frontNode = newNode;
		backNode = newNode;
	}

	return true;
}

// dequeue item in queue
bool Queue::dequeue()
{
	if (!qIsEmpty())
	{
		frontNode = frontNode->next;
		return true;
	}
	else if (frontNode == backNode)
	{
		frontNode = backNode = NULL;
		return true;
	}
	else
	{
		return false;
	}
}

// dequeue item in queue
bool Queue::dequeue(ItemType &item)
{

	if (!qIsEmpty())
	{
		item = frontNode->item;
		return dequeue();
	}
	else
		return false;
}

// get front value of queue
void Queue::getFront(ItemType &item)
{
	if (!qIsEmpty())
	{
		item = frontNode->item;
	}
	else
		return;
}

