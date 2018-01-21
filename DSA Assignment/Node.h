#pragma once
// Node.h

typedef int ItemType;

struct Node
{
	// A data item on the queue.
	ItemType item;
	// Pointer to next node.
	Node    *next;
};