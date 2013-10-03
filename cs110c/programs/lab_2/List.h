// =====================================================================================
// 
//       Filename:  List.h
// 
//    Description:  Maintains a list of items
// 
//        Version:  1.0
//        Created:  10/02/2013 12:04:46
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Nicholas Massenkoff (M4551V3), nmassenkoff@gmail.com
//        Company:  
// 
// =====================================================================================

const int MAX_LIST = 100;
typedef int ListItemType;

class List
{
	public:
		List();
		// Default Constructor
		// Destructor is supplied by compiler
		// Pre: none
		// Post: An empty list

	// List operations
		bool isEmpty() const;
		// Determines if list is empty
		// Pre: none
		// Post: none
		// Return: True if empty, False if not

		int getLength() const;
		// Determines length of list
		// pre: none
		// post: none
		// return: number of items that are in the list

		void insert(int pos, const ListItemType& newItem);
		// Inserts a new item into the list at position pos
		// pre: 1 <= pos <= getLength() + 1
		// post: newItem is inserted at position pos, and items previously
		//       at or beyond pos are shifted to the right one space.

		void push(const ListItemType& newItem);
		// Adds to the end of the list newItem
		// pre: none
		// post: newItem is added to the end of the list

		void pop(ListItemType& dataItem);
		// Retrieves the last item of the list, and removes item from list
		// pre: none
		// post: Last item of list is passed by reference to dataItem

		void remove(int pos);
		// Removes list item at pos
		// pre: 1 <= pos <= getLength()
		// post: item at pos is deleted, all other items
		//       previously after pos are shifted up the list
		//       by one.

		void retrieve(int pos, ListItemType& dataItem) const;
		// Retrieves an item from the list at pos
		// pre: 1 <= pos <= getLength()
		// post: item at pos is passed by reference to dataItem

		void clear();
		// Clears the list to empty
		// pre: none
		// post none
	private:
		// Number of items in the list
		int size;

		// Array of list items
		ListItemType items[MAX_LIST];
		
};
