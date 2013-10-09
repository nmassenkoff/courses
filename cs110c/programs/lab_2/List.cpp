// =====================================================================================
// 
//       Filename:  List.cpp
// 
//    Description:  Implementation of an array based List
// 
//        Version:  1.0
//        Created:  10/02/2013 14:11:39
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Nicholas Massenkoff (M4551V3), nmassenkoff@gmail.com
//        Company:  
// 
// =====================================================================================

#include "List.h"

List::List() : size(0)
{

}

bool List::isEmpty() const
{
	return size == 0;
}

int List::getLength() const
{
	return size;
}

void List::insert(int pos, const ListItemType& newItem)
{
	// Starting at the end of the arrays shift each element 
	// down the list by one until you reach pos

	for (int curPos = size; curPos >= pos; curPos--)
		items[curPos] = items[curPos - 1];
	
	/// Add new item
	items[pos-1] = newItem;

	// Increase size by one
	size++;

}

void List::push(const ListItemType& newItem)
{
	// Add new item to last index, and increase num items by 1
	items[size] = newItem;
	size++;
}

void List::pop(ListItemType& dataItem) 
{
	// Set dataItem to the last item of list, then remove item by reducing size by 1
	retrieve(size-1, dataItem);
	size--;
}

void List::remove(int pos)
{
	// Remove item be shifting each item after pos down by one
	for (int curPos = pos; curPos < size; curPos++)
		items[curPos-1] = items[curPos];

	// Decrease size by 1
	size--;
}

void List::retrieve(int pos, ListItemType& dataItem) const
{
	// Set dataItem to correct index of items
	dataItem = items[pos-1];
}

void List::clear()
{
	size = 0;
}
