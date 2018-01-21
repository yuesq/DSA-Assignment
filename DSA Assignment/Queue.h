#pragma once
#pragma once
#ifndef QUEUE_H
#define QUEUE_H
//#include "Node.h"
using namespace std;

typedef int ItemType;

class Queue
{

private:

	struct Node
	{
		// A data item on the queue.
		ItemType item;
		// Pointer to next node.
		Node    *next;
	};
	// pointer to front node in queue
	Node *frontNode;
	// pointer to back node in queue
	Node *backNode;

public:

	// Default constructor
	Queue();

	//Default deconstructor
	~Queue();

	//Queue operations
	bool qIsEmpty();
	bool enqueue(ItemType& item);
	bool dequeue();
	bool dequeue(ItemType& item);
	void getFront(ItemType& item);
	void displayQueue();
	int  size();
	bool dequeueItem(ItemType& item, ItemType pos);
	int  findK(int n);
};
#endif