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
	int item;
	Node *next;
};

void pushItem(Node *&head, int item)
{
	if (head == NULL)
	{
		Node *newPointer = new Node;
		newPointer->item = item;

		newPointer->next = head;
		head = newPointer;
	} 
	else
	{
		Node *last = head;
		while (last->next != NULL)
			last = last->next;

		Node *newPointer = new Node;
		newPointer->item = item;

		newPointer->next = last->next;
		last->next = newPointer;

	}

}

void retrieveItem(const Node &head, int index)
{

}

Node * merge(Node *& head1, Node *& head2)
{
	// returns a pointer to a sorted linked list that results from merging the sorted 
	//   linked lists pointed to by head1 and head2
	// preconditions: head1 and head2 point to sorted linked lists
	// postconditions: returns a pointer to a sorted linked list containing the nodes
	//   that used to be in the sorted linked lists pointed to by head1 and head2; 
	//   head1 and head2 are NULL
	Node *cur1, *cur2, *newHead, *newCur;
	
	cur1 = head1;
	cur2 = head2;
	newHead = NULL;

	Node *cur;
	cout << endl;
	cur = head1;
	cout << "Head 1 before merge: ";
	while(cur != NULL)
	{
		cout << cur->item << ' ';
		cur = cur->next;
	}
	cout << endl;
	cur = head2;
	cout << "Head 2 before merge: ";
	while(cur != NULL)
	{
		cout << cur->item << ' ';
		cur = cur->next;
	}
	cout << endl;
	while(cur1 != NULL && cur2 != NULL)
	{
		if (cur1->item <= cur2->item)
		{
			if (newHead == NULL)
			{
				newHead = cur1;
				newCur = newHead;
				cur1 = cur1->next;
			}
			else
			{
				newCur->next = cur1;
				newCur = newCur->next;
				cur1 = cur1->next;
			}
		}
		else
		{
			if (newHead == NULL)
			{
				newHead = cur2;
				newCur = newHead;
				cur2 = cur2->next;
			}
			else
			{
				newCur->next = cur2;
				newCur = newCur->next;
				cur2 = cur2->next;
			}
		}
	}

	while (cur1 != NULL)
	{
		newCur->next = cur1;
		newCur = newCur->next;
		cur1 = cur1->next;
	}

	while (cur2 != NULL)
	{
		newCur->next = cur2;
		newCur = newCur->next;
		cur2 = cur2->next;
	}

	cur = newHead;
	cout << "Head after merge: ";
	while(cur != NULL)
	{
		cout << cur->item << ' ';
		cur = cur->next;
	}
	cout << endl;

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
		cur = cur->next;
		length++;
	}
	if ( length > 1 )
	{
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


		mergeSort(head);
		mergeSort(secHead);

		merge(head, secHead);
	}
}


int main(int argc, const char *argv[])
{
	stringstream ss;
	int item;
	string input;
	int count = 0;

	cout << "Enter numbers separated by spaces: ";
	getline(cin, input);
	ss << input;

	Node *head;
	head = NULL;

	while (ss >> item)
	{
		pushItem(head, item);
	}

	ss.clear();
	
	cout << endl;
	cout << endl;
	cout << "The numbers you entered un-sorted are: ";
	Node *cur = head;
	while(cur != NULL)
	{
		cout << cur->item << ' ';
		cur = cur->next;
	}

	mergeSort(head);

	cout << endl << endl;
	cout << "The numbers you entered sorted are: ";
	cur = head;
	while (cur != NULL)
	{
		cout << cur->item << ' ';
		cur = cur->next;
	 }

	cout << endl;
	return 0;
}
