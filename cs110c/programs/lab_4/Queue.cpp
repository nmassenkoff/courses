// =====================================================================================
// 
//       Filename:  Queue.cpp
// 
//    Description:  Pointer based Queue implementation
// 
//        Version:  1.0
//        Created:  11/20/2013 00:31:42
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Nicholas Massenkoff (M4551V3), nmassenkoff@gmail.com
//        Company:  
// 
// =====================================================================================

#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue() : frontPtr(0), backPtr(0), size(0)
{

}

bool Queue::isEmpty() const
{
	if(size == 0)
		return true;
	else
		return false;
}

void Queue::enqueue(const QueueItemType& newItem)
{
	// Create new node for newItem
	QueueNode *newPtr = new QueueNode;
	newPtr->item = newItem;
	newPtr->next = 0;

	if (size == 0)
	{
		// Queue is empty so set front and back pointers
		// to the new node
		frontPtr = newPtr;
		backPtr = frontPtr;
	}
	else
	{
		// Queue is not empty, set the next pointer of the last
		// item to the new item, and update the back pointer to 
		// reference the new item
		backPtr->next = newPtr;
		backPtr = backPtr->next;
	}

	size++;
}

void Queue::dequeue(QueueItemType& nextItem)
{
	// Return the next item in the queue
	// point the front pointer to the next
	// item and deallocate the current item
	nextItem = frontPtr->item;
	QueueNode *temp = frontPtr;
	frontPtr = frontPtr->next;
	delete temp;

	if (frontPtr == 0)
		// list is now empty so set backPtr also to null
		backPtr = 0;

	size--;
}

void Queue::retrieve(int pos, QueueItemType& anItem) const
{
	// Retrieve is non destructive
	// traverse linked list until reach pos 
	int currIndex;
	QueueNode *currNode = frontPtr;

	for (currIndex = 1; currIndex < pos; currIndex++)
		currNode = currNode->next;

	anItem = currNode->item;
}

int Queue::getSize() const
{
	return size;
}
