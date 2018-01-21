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

	//if queue is not empty
	if (!qIsEmpty())
	{
		// current backnode is pointing to newnode
		backNode->next = newNode;
		// backnode is newnode
		backNode = newNode;
		// backnode now points to null
	}

	// else queue is empty
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
	// if queue is not empty
	if (!qIsEmpty())
	{
		// item is dequeued from front of queue
		frontNode = frontNode->next;
		return true;
	}
	else if (frontNode == backNode)
	{
		frontNode = NULL;
		backNode = NULL;
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
	// if queue is not empty
	if (!qIsEmpty())
	{
		// retrieve the item from front of queue
		item = frontNode->item;
		return dequeue();
	}

	// queue is empty, nothing to dequeue/retrieve
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

void Queue::displayQueue()
{
	if (qIsEmpty())
	{
		cout << "There is no queue to be displayed. " << endl;
	}
	else
	{
		Node *current = frontNode;
		bool success = true;
		while (success)
		{
			if (current != backNode)
			{
				cout << current->item << +"  ";
				current = current->next;
			}

			else
			{
				cout << current->item << endl;
				success = false;
			}
		}
	}
}

int Queue::size()
{
	int size = 0;
	Node *temp;
	temp = frontNode;

	if (!qIsEmpty())
	{
		while (temp != backNode)
		{
			temp = temp->next;
			size++;
		}

		if (temp == backNode)
		{
			size++;
		}
	}

	return size;
}


bool Queue::dequeueItem(ItemType& item, ItemType pos)
{
	bool success = !qIsEmpty();
	Node *previous;
	Node *temp;
	temp = frontNode;
	previous = temp;
	if (pos == 1)
	{
		frontNode = frontNode->next;
	}
	for (int i = 1; i < pos; i++)
	{
		previous = temp;
		temp = temp->next;
	}
	item = temp->item;
	if (temp == backNode) {
		backNode = previous;
	}
	previous->next = temp->next;
	return success;
}

int Queue::findK(int n)
{
	Node* temp = frontNode;
	int result;

	for (int i = 1; i < n; i++) {
		temp = temp->next;
	}
	result = temp->item;
	return result;
}