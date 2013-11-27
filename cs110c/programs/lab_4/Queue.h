// =====================================================================================
// 
//       Filename:  Queue.h
// 
//    Description:  Pointer based Queue implementation
// 
//        Version:  1.0
//        Created:  11/19/2013 23:46:59
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Nicholas Massenkoff (), nmassenkoff@gmail.com
//        Company:  
// 
// =====================================================================================

typedef int QueueItemType;

struct QueueNode
{
	QueueItemType item;
	QueueNode *next;
};

class Queue
{
	public:
		Queue();
		// Default Constructor
		// Destructor Supplied by compiler
		// pre: None
		// post: an emtpy queue object

		bool isEmpty() const;
		// Determines if queue is empty
		// pre: none
		// post: none
		// return: return true if queue is empty, else return false

		void enqueue(const QueueItemType& newItem);
		// Adds newItem to the queue
		// pre: none
		// post: newItem is added to the back of the queue
		// 	 back ptr is updated to point to it

		void dequeue(QueueItemType& nextItem);
		// Sets nextItem to the next item in the queue
		// pre: A non-empty queue
		// post: nextItem is set to item referenced by frontPtr
		// 	 frontPtr is then updated to reference the next
		// 	 item of the queue

		void retrieve(int pos, QueueItemType& anItem) const;
		// retrieves an item at pos position in the queue
		// pre: 1 >= pos >= getLength()
		// post: item at pos in queue is passed to anItem

		int getSize() const;
		// Returns the number of items in the queue
		// Pre: none
		// Post: none
		// Return: integer value >= 0

	private:
		// Pointer referencing the front of the queue
		QueueNode *frontPtr;

		// Pointer referencing the back of the queue
		QueueNode *backPtr;

		// Integer to keep track of # of itemes in queue
		int size;
};
