#pragma once
#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"
using namespace std;

typedef int ItemType;

class Queue
{
private:
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
};
#endif