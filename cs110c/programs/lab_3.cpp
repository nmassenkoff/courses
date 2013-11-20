// =====================================================================================
// 
//       Filename:  lab_3.cpp
// 
//    Description:  Creates a linked listed of integers as provided by the user
//    		    and then sorts these integers in ascending order using a mergesort
//    		    algorithm
// 
//        Version:  1.0
//        Created:  10/29/2013 20:35:23
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Nicholas Massenkoff (M4551V3), nmassenkoff@gmail.com
//        Company:  
// 
// =====================================================================================


#include <iostream>
#include <sstream>

using namespace std;

struct Node
{
	// Node struct for our linked list
	int item;
	Node *next;
};

void pushItem(Node *&head, int item)
{
	// Creates a new Node with item as it's value
	// and adds it to the end of the linked list referenced
	// by head
	// Precondition:  head points to a link list of Nodes,
	// 		  Item is an integer value
	// Postcondition: The linked list referenced by head,
	// 		  has one more Noded added to the list
	// 		  with the value item and the next Node = NULL
	if (head == NULL)
	{
		// Linked list is empty add node to beginning
		Node *newPointer = new Node;
		newPointer->item = item;

		newPointer->next = head;
		head = newPointer;
	} 
	else
	{
		// Linked list is not empty, add node to the end
		Node *last = head;
		while (last->next != NULL)
			// Locate the last Node
			last = last->next;

		Node *newPointer = new Node;
		newPointer->item = item;

		newPointer->next = last->next;
		last->next = newPointer;

	}

}

Node * merge(Node *& head1, Node *& head2)
{
	// returns a pointer to a sorted linked list that results from merging the sorted 
	//   linked lists pointed to by head1 and head2
	// preconditions: head1 and head2 point to sorted linked lists
	// postconditions: returns a pointer to a sorted linked list containing the nodes
	//   that used to be in the sorted linked lists pointed to by head1 and head2; 
	//   head1 and head2 are NULL

	// Node pointers to keep track of the newly created sorted list
	Node *newHead, *newCur;
	newHead = NULL;

	// First determine first item of newHead
	if (head1->item <= head2->item)
	{
		newHead = head1;
		head1 = head1->next;
	} else {
		newHead = head2;
		head2 = head2->next;
	}

	newCur = newHead;

	while(head1 != NULL && head2 != NULL)
	{
		// Compare the first value of each list
		// and whichever one is less than the other
		// detach from that list and add it to the new
		// list
		// If one of the lists reaches the end
		// then stop

		// Now merge rest of list
		if (head1->item <= head2->item)
		{
			// First item of head1 is less than or equal to first
			// item of head2, so detach from list1 and append to new list
			newCur->next = head1;
			newCur = newCur->next;
			head1 = head1->next;
		} else {
			// First item of head2 is less than first item
			// of head1, so detach from list2 and append to new list
			newCur->next = head2;
			newCur = newCur->next;
			head2 = head2->next;
		}
	}

	// Either one of head1 or head2 has reached the end
	// whichever list with more items, add them one by one
	// to the end of new list
	while (head1 != NULL)
	{
		newCur->next = head1;
		newCur = newCur->next;
		head1 = head1->next;
	}

	while (head2 != NULL)
	{
		newCur->next = head2;
		newCur = newCur->next;
		head2 = head2->next;
	}

	return newHead;
}

void mergeSort(Node *& head)
{
	// sorts the link list pointed to by head 
	// precondition: head points to a linked list of items
	// postcondition: head points to a sorted linked list, containing the items
	//   that were in the original linked list, but in sorted order
	

	int length = 0;
	Node *cur = head;
	while (cur != NULL)
	{
		// For mergesort must split the list in half and then recursively
		// mergesort each of those halves.
		// First determine length of list
		cur = cur->next;
		length++;
	}
	if ( length > 1 )
	{
		// Base case is a length of one, at which point no sorting is needed
		// Otherwise traverse the linked list until reach the middle and split 
		// the list at that point.  The first half is referenced by head, and the 
		// second half is referenced by secHead
		Node *secHead = head;
		Node *prev = NULL;

		int counter = 0;
		while (counter < length/2)
		{
			prev = secHead;
			secHead = secHead->next;
			counter++;
		}
		prev->next = NULL;

		// Recursively mergesort each of these halves
		mergeSort(head);
		mergeSort(secHead);

		// merge the now sorted halves and head to point to the newly merged list
		head = merge(head, secHead);
	}
}


int main(int argc, const char *argv[])
{
	// Variables to handle user input
	stringstream ss;
	string input;
	int item;
	int count = 0;

	// Prompt user for numbers
	cout << "Enter numbers separated by spaces: " << endl;
	getline(cin, input);
	ss << input;

	// Node head pointer for main list
	Node *head;
	head = NULL; // no items yet

	while (ss >> item)
	{
		// proccess each item entered by user, adding them to the end of the linked list
		// referenced by head
		pushItem(head, item);
	}

	ss.clear();
	
	// Show user original order
	cout << endl;
	cout << "The numbers you entered un-sorted are: " << endl;
	Node *cur = head;
	while(cur != NULL)
	{
		cout << cur->item << ' ';
		cur = cur->next;
	}

	// Mergesort the list
	mergeSort(head);

	// Show user the sorted order
	cout << endl ;
	cout << "The numbers you entered sorted are: " << endl;
	cur = head;
	while (cur != NULL)
	{
		cout << cur->item << ' ';
		cur = cur->next;
	 }

	cout << endl;
	return 0;
}
